#include <kernel/utilities/license.h>
#include <sys/stat.h> //for stat 

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


using namespace std; 

const string License::licensefile = "license.txt";

const string License::machineidfile = "machineid.txt";

const string License::licin = "license.in";

//const string License::privateKey = "VjansfoklgmAFIORWF969834OKFEORPK$05439KOPFKWPOEKF";


bool License::FileExists(const string& filename) {

	struct stat buf;
	return (stat(filename.c_str(), &buf) != -1);

}

bool License::CheckLicense(){

	ifstream lic_in(License::licensefile.c_str(), ios::in);

	if (lic_in.good()){
			
		lic_in.close();

		if (!CheckLicense(GenerateId())) return false;

	} else {
		lic_in.close();
	
		cout << "No license file." << endl;

		ifstream mach_in(machineidfile.c_str(), ios::in);

		if (mach_in.good()){
			
			cout << "Machine id file present." << endl
			<< "In order to generate new machine id please remove the current one." << endl;
			mach_in.close();
			
			return false;
			
		} else {
			mach_in.close();

			cout << "Generating machine id string... ";

			string machineid = GenerateId();

			cout << " complete." << endl << "Your machine id is: " 
				<< endl << machineid << endl; 

			ofstream mach_out(machineidfile.c_str(),ios::out);

			mach_out << "Machine id file. Generated by Rosetta. Please do not edit this file."  << endl << "Machine id:" << endl << machineid;

			mach_out.close();

			cout << "It has been saved in current directory for" 
			<< " your convenience as " 
			<< machineidfile << endl;

			return false;
		};

	};

	return true;

};

bool License::CheckLicense(string id, long int k, long int key2){
	
	string tmp;

	string e = ReadIdFile();	

	int d,m,y,ld,lm,ly;
	
	//int months[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	istringstream in(Decrypt(k,e));

	in >> tmp >> d >> m >> y >> ld >> lm >> ly >> tmp;

#ifdef WIN32

	CTime time = CTime::GetCurrentTime();
	CTimeSpan to = CTimeSpan(ly*365+lm*30+ld,0,0,0);
	CTime from = CTime(y,m,d,0,0,0);
	if (time> (from+to) || time < from ){

		cout << "Your license has expired or it is not yet valid." << endl;
		return false;
	};
	
#endif
	
#if LINUX && !(SOLARIS)
	time_t date = time(NULL);	
	long int number_of_seconds = (ly*365 + lm*30 + ld)*86400;
	tm data;
	
	data.tm_sec = 0;
	data.tm_min = 0;
	data.tm_hour = 0;
	data.tm_mday = d;
	data.tm_mon = m-1;
	data.tm_year = y - 1900;

	time_t date_num = mktime(&data);

	if (date > (number_of_seconds + date_num) || date < date_num){

		cout << "Your licence has expired or it is not yet valid." << endl; 
		return false;
	};

#endif
	if (id == Encrypt(key2,tmp)) return true;

	cout << "License mismatch. Aborting." << endl;

	return false;
};

/*
bool FileExists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}
*/

string License::ReadIdFile(string location){

	string e="";
	string e2="";

#ifndef GENERATOR
//	ifstream fileinput(location.c_str(),ios_base::in);
//	while (fileinput.good()) {
//		fileinput >> encrypted;
//	}
	//FileExists is defined in keycrypto.cpp
	if (!FileExists(location)) {
		cout << "License is missing. Aborting." << endl;
		return false;
	}

	KeyCrypto crypto;
	std::string decrypted = crypto.ReadFromLicense(location);

	istringstream input(decrypted);	
#else
	ifstream input(location.c_str(), ios_base::in);
#endif

	bool sw = true;
	while (sw && input.good()){

		e2 = e;
		input >> e;
		if ((e2+" "+e)=="Machine id:" || (e2+" "+e)=="License id:") sw = false; 

	};

	if (!sw) input >> e;
	else cout << "Error opening id file." << endl;

//	input.close();
	return e ;

}



string
License::GetFirstDeviceName() { 

   int    iSocket = -1;
   struct if_nameindex* pIndex = 0;
   struct if_nameindex* pIndex2 = 0;

   if ((iSocket = socket(PF_INET, SOCK_DGRAM, 0)) < 0)
   {
      perror("socket");
      exit(105);
   }

   pIndex = pIndex2 = if_nameindex();

   while ((pIndex != NULL) && (pIndex->if_name != NULL))
   {
      struct ifreq req;

	if (strcmp(pIndex->if_name, "lo") != 0) {
		return pIndex->if_name;
	}

//      printf("%d: %s\n", pIndex->if_index, pIndex->if_name);

//      strncpy(req.ifr_name, pIndex->if_name, IFNAMSIZ);

//      if (ioctl(iSocket, SIOCGIFADDR, &req) < 0)
//      {
//         if (errno == EADDRNOTAVAIL)
//         {
//            printf("\tN/A\n");
//            ++pIndex;
//            continue;
//         }

//         perror("ioctl");

//         close(iSocket);
//         exit(106);
//      }

//      printf("\t %s\n", inet_ntoa(((struct sockaddr_in*)&req.ifr_addr)->sin_addr));
      ++pIndex;
   }

//   if_freenameindex(pIndex2);

//   close(iSocket);
	cerr << "No NIC available. Exiting..." << endl;
	exit(106);
	return NULL;
}





string License::GenerateId(long int key){

	ostringstream oss(ostringstream::out);

#ifdef WIN32
	// Retrieving windows serial number from registry

	HKEY regkey;
    	char serial_number [1024];

        if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion", 0, KEY_QUERY_VALUE, &regkey) == ERROR_SUCCESS){
                DWORD size=1023;
                RegQueryValueEx(regkey, "Productid", NULL, NULL,
                    (LPBYTE)serial_number,&size);
        } else {
		oss << "Reading Windows ProductId from registry failed" << endl;
	};
    
        RegCloseKey(regkey);

	oss << serial_number;

#endif

#if LINUX && !SOLARIS
	// This part reads mac addres of eth0
        int sockfd = 1;
	// Return value for the IO op. Get error value from errno if -1.
	int nIOstate = 0;
        struct ifreq ifrr;

        ifrr.ifr_addr.sa_family = AF_INET;
	//Replaced eth0. -N
	//Replaced enp1s0. -N
        strncpy(ifrr.ifr_name, (GetFirstDeviceName()).c_str(), sizeof(ifrr.ifr_name));

	//Moved these out to allow for better debugging/errorchecking. -N 
	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
	nIOstate = ioctl(sockfd, SIOCGIFHWADDR, &ifrr);

        if ((sockfd >= 0) && (nIOstate == 0)) {

                unsigned char* u = (unsigned char *) ifrr.ifr_addr.sa_data;

                if (u[0] + u[1] + u[2] + u[3] + u[4] + u[5]) {
                        oss << hex << setfill('0') << setw(2) << (int)u[0] << ":"
                            << hex << setfill('0') << setw(2) << (int)u[1] << ":"
                            << hex << setfill('0') << setw(2) << (int)u[2] << ":"
                            << hex << setfill('0') << setw(2) << (int)u[3] << ":"
                            << hex << setfill('0') << setw(2) << (int)u[4] << ":"
                            << hex << setfill('0') << setw(2) << (int)u[5];
                };
        } else {
		oss << "Reading MAC address failed" << endl;
		exit(1);
	};	

#endif

	return Encrypt(key,oss.str());
};

string License::Encrypt(long int key, string enc){
	
	string result;
	result.reserve(enc.size()*base_exp);
	Generator gen = Generator(-key);

	for (int i=0; i<enc.size(); i++){ 

		int ran = gen.Get()-enc[i];
		
		char ttt[base_exp];
		for (int j=0; j < base_exp; j++){
		
			ttt[base_exp-1-j] = (ran%base + shift);
			ran /= base;

		};
		result.push_back(ttt[0]);
		result.push_back(ttt[1]);
		result.push_back(ttt[2]);
		result.push_back(ttt[3]);
		result.push_back(ttt[4]);
	};





	return result;


};

string License::Decrypt(long int key, string dec){

	string result = "";
	Generator gen = Generator(-key);

	for (int i=0; i<dec.size(); i+=base_exp){ 

		int num = 0;
		int tmp_base = 1;
		for (int j=0; j<base_exp-1;j++) tmp_base *= base;
		
		for (int j=0; j<base_exp; j++){

			num += (dec[i+j]-shift)*tmp_base;
			tmp_base /= base;

		};
		result.push_back(gen.Get()-num);

	};

	return result;

};


