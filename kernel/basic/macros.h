//-------------------------------------------------------------------
// Author........: Aleksander �hrn
// Date..........:
// Description...:
// Revisions.....:
//===================================================================

#ifndef __MACROS_H__
#define __MACROS_H__

#include <copyright.h>

//-------------------------------------------------------------------
// Name..........: DECLAREID
// Author........: Aleksander �hrn
// Date..........: 960307
// Description...: Macro for declaring identifiers.
// Revisions.....:
//===================================================================

#define DECLAREID(id)                                               \
extern const Id id;

//-------------------------------------------------------------------
// Name..........: IMPLEMENTID
// Author........: Aleksander �hrn
// Date..........: 960307
// Description...: Macro for implementing identifiers.
// Revisions.....:
//===================================================================

#define IMPLEMENTID(id, classname, description)                     \
const Id id = IdHolder::Register(classname, description);

//-------------------------------------------------------------------
// Name..........: DECLAREIDMETHODS
// Author........: Aleksander �hrn
// Date..........: 960307
// Description...: Macro for declaring identifier methods.
// Revisions.....:
//===================================================================

#define DECLAREIDMETHODS()                                          \
virtual bool IsA(Id id) const;                                      \
virtual Id   GetId() const;

//-------------------------------------------------------------------
// Name..........: IMPLEMENTIDMETHODS
// Author........: Aleksander �hrn
// Date..........: 960307
// Description...: Macro for implementing identifier methods.
// Revisions.....:
//===================================================================

#define IMPLEMENTIDMETHODS(classname, id, basename)                 \
bool                                                                \
classname::IsA(Id x) const {                                      \
	return (x == id || basename::IsA(x));                           \
}                                                                   \
	                                                                  \
Id                                                                  \
classname::GetId() const {                                        \
	return id;                                                        \
}

//-------------------------------------------------------------------
// Name..........: Installation macros
// Author........: Aleksander �hrn
// Date..........:
// Description...: Macros for installing prototype objects.
//                 This macro hides the fact that dialogs are not
//                 relevant outside the ROSETTA GUI, and enables one
//                 keep the installation call interface uniform.
// Comments......:
// Revisions.....:
//===================================================================

#define INSTALLSTRUCTURE(classname)                   ObjectManager::Install(classname);

#if defined(_ROSGUI)
	#define INSTALLALGORITHM(classname, dialogname)               \
			ObjectManager::Install(classname, dialogname);
#else
	#define INSTALLALGORITHM(classname, dialogname)     ObjectManager::Install(classname);
#endif

//-------------------------------------------------------------------
// Name..........: Genomic mode macros
// Author........: Robin Andersson
// Date..........: 040616
// Description...: Macros for explicitly connect genomic algorithms to
//                 certain nodes. Needed in order to build the project
//                 tree with node names not derived by the type of
//                 algorithm.
//                 Macro for defining an algorithm to be genomic 
// Comments......:
// Revisions.....:
//===================================================================

#if defined(_ROSGUI)
	#define GENOMICALGORITHM(identifier) \
		ModeManager::SetGenomic(identifier);
	#define CONNECTTONODE(identifier, nodename) \
		ModeManager::AddNode(nodename); \
		ModeManager::ConnectToNode(identifier,nodename);
#endif
//-------------------------------------------------------------------
// Name..........: Container macros
// Author........: Aleksander �hrn
// Date..........:
// Description...: Macros to (i) save keystrokes and (ii) to make any
//                 later changes in containers less painful, e.g., if
//                 we want to use something else than STL.
//
// Comments......: If an STL alternative to vectors is desired, the
//                 Array template can be used instead.
//
// Revisions.....: 
//===================================================================

#define STLList(type)                                 std::list<type >
#define STLMap(type1, type2)                          std::map<type1, type2, std::less<type1 > >
#define STLPair(type1, type2)                         std::pair<type1, type2 >
#define STLSet(type)                                  std::set<type, std::less<type > >
#define STLVector(type)                               std::vector<type >

#ifndef GCC_STL
	#define STLHashSet(type)                              std::hash_set<type >
	#define STLHashMap(type1, type2)                      std::hash_map<type1, type2 >
#else
	#define STLHashSet(type)                              __gnu_cxx::hash_set<type >
	#define STLHashMap(type1, type2)                      __gnu_cxx::hash_map<type1, type2 >
#endif

#define List(type)                                    STLList(type)
#define Map(type1, type2)                             STLMap(type1, type2)
#define Pair(type1, type2)                            STLPair(type1, type2)
#define Set(type)									  STLSet(type)
#define Vector(type)                                  STLVector(type)
#define HashMap(type1, type2)                         STLHashMap(type1, type2)
#define HashSet(type)                                 STLHashSet(type)
#define Map2(type1, type2)                             std::map<type1, type2>

//-------------------------------------------------------------------
// Name..........: Casting macros
// Author........: Aleksander �hrn
// Date..........: 960511
// Description...: Macros to ease porting to "old" compilers that do
//                 not yet support the new C++-style casts.
// Comments......: MSVC++ 4.2 seems a lot more fussy than MSVC++ 4.0
//                 about the correct usage of the new casts.  For
//                 instance, MSVC++ 4.0 allows dynamic_cast to
//                 also cast away constness, while MSVC++ 4.2 insists
//                 on such constructs being composed of both a
//                 dynamic_cast and a const_cast.
// Revisions.....:
//===================================================================

#if defined(_OLDCASTS)
	#define const_cast(type, expression)                ((type) (expression))
	#define dynamic_cast(type, expression)              ((type) (expression))
	#define static_cast(type, expression)               ((type) (expression))
	#define reinterpret_cast(type, expression)          ((type) (expression))
#else
	#define const_cast(type, expression)                const_cast<type >(expression)
	#define dynamic_cast(type, expression)              dynamic_cast<type >(expression)
	#define static_cast(type, expression)               static_cast<type >(expression)
	#define reinterpret_cast(type, expression)          reinterpret_cast<type >(expression)
#endif

#endif 
