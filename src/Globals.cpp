#include "tp_pipeline_colmap/Globals.h"
//#include "tp_pipeline_colmap/step_delegates/StubStepDelegate.h"

#include "tp_pipeline/StepDelegateMap.h"

//##################################################################################################
namespace tp_pipeline_colmap
{
TDP_DEFINE_ID(                       colmapSID,                           "Colmap")

//##################################################################################################
void createStepDelegates(tp_pipeline::StepDelegateMap& stepDelegates)
{
  TP_UNUSED(stepDelegates);
  //stepDelegates.addStepDelegate(new StubStepDelegate);
}
}
