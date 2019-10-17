//-------------------------------------------------------------------
// Author........: Aleksander �hrn
// Date..........:
// Description...:
// Revisions.....:
//===================================================================

#include <stdafx.h> // Precompiled headers.
#include <copyright.h>

#include <kernel/algorithms/prologreductexporter.h>

#include <kernel/structures/reducts.h>
#include <kernel/structures/reduct.h>

#include <kernel/utilities/systemkit.h>

#include <kernel/system/fstream.h>

//-------------------------------------------------------------------
// Methods for class PrologReductExporter.
//===================================================================

//-------------------------------------------------------------------
// Constructors/destructor.
//===================================================================

PrologReductExporter::PrologReductExporter() {
}

PrologReductExporter::~PrologReductExporter() {
}

//-------------------------------------------------------------------
// Methods inherited from Identifier.
//===================================================================

IMPLEMENTIDMETHODS(PrologReductExporter, PROLOGREDUCTEXPORTER, ReductExporter)

//-------------------------------------------------------------------
// Methods inherited from Exporter.
//===================================================================

//-------------------------------------------------------------------
// Method........: ExportPrologue
// Author........: Aleksander �hrn
// Date..........:
// Description...:
// Comments......: Consider using IOKit instead.
// Revisions.....:
//===================================================================

bool
PrologReductExporter::ExportPrologue(ofstream &stream, const Structure &structure) const {

	// Cast to already verified type (in Apply method).
	Handle<Reducts> reducts = dynamic_cast(Reducts *, const_cast(Structure *, &structure));

	// Write some general information.
	stream << "% Reducts generated by ROSETTA." << endl;
	stream << "% Exported " << SystemKit::GetTimestamp() << " by " << SystemKit::GetUser() << "." << endl;
	stream << "%" << endl;
	stream << "% " << reducts->GetName() << endl;
	stream << "% " << reducts->GetNoReducts() << " reducts." << endl;
	stream << endl;

	return true;

}

//-------------------------------------------------------------------
// Methods inherited from ReductExporter.
//===================================================================

//-------------------------------------------------------------------
// Method........: ExportReduct
// Author........: Aleksander �hrn
// Date..........:
// Description...: Overloaded to deal with Prolog syntax.
// Comments......:
// Revisions.....:
//===================================================================

bool
PrologReductExporter::ExportReduct(ofstream &stream, int reduct_no, const Reduct &reduct) const {

	String formatted;

	bool masked = true;

	// Generate Prolog format.
	if (!reduct.FormatProlog(formatted, "r" + String::Format(reduct_no + 1), GetDecisionTable(), masked)) {
		Message::Error("Error formatting reduct.");
		return false;
	}

	// Dump formatted reduct to file stream.
	stream << formatted << endl << endl;

	return true;

}

PrologReductExporter *
PrologReductExporter::Clone() {
   return new PrologReductExporter;
}
 