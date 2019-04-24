#ifndef tp_pipeline_colmap_Globals_h
#define tp_pipeline_colmap_Globals_h

#include "tp_utils/StringID.h"

namespace tp_data
{
class CollectionFactory;
}

namespace tp_pipeline
{
class StepDelegateMap;
}

//##################################################################################################
//! Add colmap to the pipeline pipeline.
namespace tp_pipeline_colmap
{
TDP_DECLARE_ID(                       colmapSID,                           "Colmap")

//##################################################################################################
//! Add the step delegates that this module provides to the StepDelegateMap
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates, const tp_data::CollectionFactory* collectionFactory);

//##################################################################################################
//! Static initialization of this module, see TP_STATIC_INIT in dependencies.pri
int staticInit();

}

#endif
