add_llvm_component_library(LLVMDLXInfo
  DLXTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  DLX
  )
