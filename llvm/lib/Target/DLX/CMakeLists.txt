add_llvm_component_group(DLX)

set(LLVM_TARGET_DEFINITIONS DLX.td)

# tablegen(LLVM DLXGenAsmMatcher.inc -gen-asm-matcher)
# tablegen(LLVM DLXGenAsmWriter.inc -gen-asm-writer)
# tablegen(LLVM DLXGenCallingConv.inc -gen-callingconv)
# tablegen(LLVM DLXGenDAGISel.inc -gen-dag-isel)
# tablegen(LLVM DLXGenDisassemblerTables.inc -gen-disassembler)
# tablegen(LLVM DLXGenInstrInfo.inc -gen-instr-info)
# tablegen(LLVM DLXGenMCCodeEmitter.inc -gen-emitter)
tablegen(LLVM DLXGenRegisterInfo.inc -gen-register-info)
# tablegen(LLVM DLXGenSDNodeInfo.inc -gen-sd-node-info)
# tablegen(LLVM DLXGenSubtargetInfo.inc -gen-subtarget)

add_public_tablegen_target(DLXCommonTableGen)

add_llvm_target(DLXCodeGen
  # DLXAsmPrinter.cpp
  # DLXDelaySlotFiller.cpp
  # DLXFrameLowering.cpp
  # DLXInstrInfo.cpp
  # DLXISelDAGToDAG.cpp
  # DLXISelLowering.cpp
  # DLXMachineFunctionInfo.cpp
  # DLXMCInstLower.cpp
  # DLXMemAluCombiner.cpp
  # DLXRegisterInfo.cpp
  # DLXSelectionDAGInfo.cpp
  # DLXSubtarget.cpp
  DLXTargetMachine.cpp
  # DLXTargetObjectFile.cpp

  LINK_COMPONENTS
  Analysis
  AsmPrinter
  CodeGen
  CodeGenTypes
  Core
  # DLXAsmParser
  # DLXDesc
  DLXInfo
  MC
  SelectionDAG
  Support
  Target
  TargetParser
  TransformUtils

  ADD_TO_COMPONENT
  DLX
  )

# add_subdirectory(AsmParser)
# add_subdirectory(Disassembler)
# add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)
