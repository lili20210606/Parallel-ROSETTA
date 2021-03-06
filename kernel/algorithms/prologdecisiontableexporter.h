//-------------------------------------------------------------------
// Author........: Aleksander �hrn
// Date..........:
// Description...:
// Revisions.....:
//===================================================================

#ifndef __PROLOGDECISIONTABLEEXPORTER_H__
#define __PROLOGDECISIONTABLEEXPORTER_H__

#include <copyright.h>

#include <kernel/algorithms/decisiontableexporter.h>

//-------------------------------------------------------------------
// Class.........: PrologDecisionTableExporter
// Author........: Aleksander �hrn
// Date..........:
// Description...: Exports a decision table to Prolog format.
// Revisions.....:
//===================================================================

class PrologDecisionTableExporter : public DecisionTableExporter {
protected:

  //- Methods inherited from Exporter................................
	virtual bool ExportPrologue(ofstream &stream, const Structure &structure) const;

  //- Methods inherited from DecisionTableExporter...................
	virtual bool ExportInformationVector(ofstream &stream, const DecisionTable &table, int object_no, bool masked) const;

public:

  //- Constructors/destructor........................................
  PrologDecisionTableExporter();
  virtual ~PrologDecisionTableExporter();

	virtual PrologDecisionTableExporter   *Clone();

  //- Methods inherited from Identifier..............................
	DECLAREIDMETHODS()

};

#endif 
