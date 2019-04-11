#ifndef tp_pipeline_colmap_Globals_h
#define tp_pipeline_colmap_Globals_h

#include "tp_utils/StringID.h"

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
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates);
}

#endif
