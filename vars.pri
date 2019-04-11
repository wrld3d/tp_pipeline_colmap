fTARGET = tp_pipeline_colmap
TEMPLATE = lib

DEFINES += TP_PIPELINE_CAFFE2_LIBRARY

SOURCES += src/Globals.cpp
HEADERS += inc/tp_pipeline_colmap/Globals.h


#-- Delegates --------------------------------------------------------------------------------------
SOURCES += src/step_delegates/StubStepDelegate.cpp
HEADERS += inc/tp_pipeline_colmap/step_delegates/StubStepDelegate.h


#-- Members ----------------------------------------------------------------------------------------
SOURCES += src/members/StubMember.cpp
HEADERS += inc/tp_pipeline_colmap/members/StubMember.h
