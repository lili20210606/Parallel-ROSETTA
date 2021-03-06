//-------------------------------------------------------------------
// Author........: Aleksander �hrn
// Date..........:
// Description...:
// Revisions.....: A� 990325: Removed some '#if defined(_RSES)' stuff.
//===================================================================

#ifndef __IDS_H__
#define __IDS_H__

#include <copyright.h>

#include <kernel/basic/types.h>
#include <kernel/basic/macros.h>

//-------------------------------------------------------------------
// Identifier declarations
//===================================================================

DECLAREID(ALGORITHM)
DECLAREID(ANNOTATEDSTRUCTURE)
DECLAREID(ANNOTATION)
DECLAREID(ANONYMIZER)
DECLAREID(APPROXIMATION)
DECLAREID(APPROXIMATOR)
DECLAREID(ATTRIBUTE)
DECLAREID(BATCHCLASSIFICATION)
DECLAREID(BATCHCLASSIFIER)
DECLAREID(BINARYOUTCOMECURVE)
DECLAREID(BINARYSPLITTER)
DECLAREID(BOOLEANFUNCTION)
DECLAREID(BOOLEANPOSFUNCTION)
DECLAREID(BOOLEANSOPFUNCTION)
DECLAREID(BRORTHOGONALSCALER)
DECLAREID(CALIBRATIONCURVE)
DECLAREID(CLASSIFICATION)
DECLAREID(CLASSIFIER)
DECLAREID(CONFUSIONMATRIX)
DECLAREID(COMBINATORIALCOMPLETER)
DECLAREID(COMPLETER)
DECLAREID(CONDITIONEDCOMBINATORIALCOMPLETER)
DECLAREID(CONDITIONEDCOMPLETER)
DECLAREID(CONDITIONEDMEANCOMPLETER)

//Ewa Makosa 03.06.2005
DECLAREID(CPPGENERALRULEEXPORTER)

DECLAREID(CPPRULEEXPORTER)
DECLAREID(CVCLASSIFIER)
DECLAREID(CVSERIALEXECUTOR)
DECLAREID(DECISIONTABLE)
DECLAREID(DECISIONTABLEEXPORTER)
DECLAREID(DECISIONTABLEIMPORTER)
DECLAREID(DECISIONTABLES)
DECLAREID(DICTIONARY)
DECLAREID(DICTIONARYEXPORTER)
DECLAREID(DICTIONARYIMPORTER)
DECLAREID(DISCERNIBILITYEXPORTER)
DECLAREID(DISCERNIBILITYFUNCTION)
DECLAREID(DISCERNIBILITYFUNCTIONEXPORTER)
DECLAREID(DISCERNIBILITYMATRIX)
DECLAREID(DYNAMICREDUCER)
DECLAREID(ENTROPYSCALER)
DECLAREID(EQUALFREQUENCYSCALER)
DECLAREID(EQUIVALENCECLASS)
DECLAREID(EQUIVALENCECLASSES)
DECLAREID(EXECUTOR)
DECLAREID(EXPORTER)
DECLAREID(FEATURESELECTOR)
DECLAREID(FILTER)
DECLAREID(FLOATATTRIBUTE)
DECLAREID(FTEST)
DECLAREID(FUNCTIONALCLASSIFIER)
DECLAREID(GENERALIZEDDECISION)

//Ewa Makosa 03.06.2005
DECLAREID(GENERALRULE)
DECLAREID(GENERALRULEEXPORTER)
DECLAREID(GENERALRULES)

DECLAREID(GRAPH)
DECLAREID(REYREDUCER)  
DECLAREID(HISTORY)
DECLAREID(HISTORYENTRY)
DECLAREID(HOLTE1RREDUCER)
DECLAREID(HTMLREPORTER)
DECLAREID(IDENTIFIER)
DECLAREID(IMPORTER)
DECLAREID(INDISCERNIBILITYGRAPH)
DECLAREID(INDISCERNIBILITYGRAPHEXPORTER)
DECLAREID(INFORMATIONVECTOR)
DECLAREID(INTEGERATTRIBUTE)
DECLAREID(JOHNSONREDUCER)
DECLAREID(KIDNAPPER)
DECLAREID(KSDECISIONTABLE)
DECLAREID(KSINFORMATIONVECTOR)
DECLAREID(KSREDUCT)
DECLAREID(KSRULE)
DECLAREID(KSRULEGENERATOR)
DECLAREID(LOOCVSERIALEXECUTOR)
DECLAREID(LOADER)
DECLAREID(LOADFEATURESELECTION)
DECLAREID(MANUALFEATURESELECTOR)
DECLAREID(MANUALREDUCER)
DECLAREID(MANUALSCALER)
DECLAREID(MATLABDECISIONTABLEEXPORTER)
DECLAREID(MEANCOMPLETER)
DECLAREID(MYDECISIONTABLEEXPORTER)
DECLAREID(MYDECISIONTABLEIMPORTER)

// sus
DECLAREID(ARFFDECISIONTABLEIMPORTER)
DECLAREID(ADXDECISIONTABLEIMPORTER)
DECLAREID(ARFFDECISIONTABLEEXPORTER)
DECLAREID(ADXDECISIONTABLEEXPORTER)

//Ewa Makosa 03.06.2005
DECLAREID(MYGENERALRULEFILTER)

DECLAREID(MYPOSDECISIONTABLEIMPORTER)
DECLAREID(MYREDUCTEXPORTER)
DECLAREID(MYREDUCTFILTER)
DECLAREID(MYREDUCTIMPORTER)
DECLAREID(MYREDUCTSHORTENER)
DECLAREID(MYRULEEXPORTER)
DECLAREID(MYRULEFILTER)
DECLAREID(NAIVEBAYESCLASSIFIER)
DECLAREID(NAIVESCALER)
DECLAREID(OBJECTTRACKINGVOTER)
DECLAREID(ODBCDECISIONTABLEIMPORTER)
DECLAREID(ORTHOGONALFILESCALER)
DECLAREID(ORTHOGONALSCALER)
DECLAREID(PARALLELEXECUTOR)
DECLAREID(PARENTSTRUCTURE)
DECLAREID(PARTITIONER)
DECLAREID(PERMCVSERIALEXECUTOR)
DECLAREID(PERMLOOCVSERIALEXECUTOR)
DECLAREID(PERMUTATIONTEST)
DECLAREID(PERSISTENT)
// -N 22/08/13 RR----------------------------------
DECLAREID(MCFEATURESELECTOR)
DECLAREID(PRINCIPALCOMPONENTANALYSIS)
DECLAREID(PROJECT)
DECLAREID(PROLOGDECISIONTABLEEXPORTER)

//Ewa Makosa 03.06.2005
DECLAREID(PROLOGGENERALRULEEXPORTER)

DECLAREID(PROLOGREDUCTEXPORTER)
DECLAREID(PROLOGRULEEXPORTER)
DECLAREID(QUALITYRULEFILTER)
DECLAREID(QUALITYRULEFILTERLOOP)
DECLAREID(REDUCER)
DECLAREID(REDUCT)
DECLAREID(REDUCTCOSTFILTER)
DECLAREID(REDUCTEXPORTER)
DECLAREID(REDUCTFILTER)
DECLAREID(REDUCTIMPORTER)
DECLAREID(REDUCTPERFORMANCEFILTER)
DECLAREID(REDUCTS)
DECLAREID(REDUCTSHORTENER)
DECLAREID(REMOVALCOMPLETER)
DECLAREID(REPORTER)
DECLAREID(RFEATURESELECTOR)
DECLAREID(ROCCURVE)
DECLAREID(RULE)
DECLAREID(RULEBASEDCLASSIFICATION)
DECLAREID(RULEBASEDCLASSIFIER)
DECLAREID(RULEEXPORTER)
DECLAREID(RULEFILTER)

// Ewa Makosa 03.06.2005---------------------------
DECLAREID(RULEGENERALIZER)
// Ewa Makosa 03.06.2005---------------------------

DECLAREID(RULEGENERATOR)

// Ewa Makosa 03.06.2005---------------------------
DECLAREID(RULEGROUPGENERALIZER)
DECLAREID(RULEPAIRWISEGENERALIZER)
// Ewa Makosa 03.06.2005---------------------------

DECLAREID(RULES)

// Ewa Makosa 03.06.2005---------------------------
DECLAREID(RULESHORTENER)
DECLAREID(RULETUNER)
// Ewa Makosa 03.06.2005---------------------------

DECLAREID(SAVER)
DECLAREID(SAVGENETICREDUCER)
DECLAREID(SCALER)
DECLAREID(SCRIPTALGORITHM)
DECLAREID(SEMINAIVESCALER)
DECLAREID(SERIALEXECUTOR)
DECLAREID(SERIALEXECUTORLOOP)

//Ewa Makosa 06.06.2005
DECLAREID(SIMPLECOVERFILTER)

DECLAREID(SPLITTER)
DECLAREID(STANDARDVOTER)
DECLAREID(STRINGATTRIBUTE)
DECLAREID(STRUCTURE)
DECLAREID(STRUCTURECREATOR)
DECLAREID(STRUCTURES)
DECLAREID(TEMPLATESCALER)
DECLAREID(TEXTFILE)
DECLAREID(TTEST)
DECLAREID(VALUESPLITTER)
DECLAREID(VOTER)
DECLAREID(XMLDECISIONTABLEEXPORTER)

// Ewa Makosa 03.06.2005--------------------------- 
DECLAREID(XMLGENERALRULEEXPORTER)

DECLAREID(XMLREDUCTEXPORTER) 
DECLAREID(XMLREPORTER) 
DECLAREID(XMLRULEEXPORTER) 


#endif
 
