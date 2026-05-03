#ifndef LLVM_LIB_TARGET_DLX_DLXTARGETMACHINE_H
#define LLVM_LIB_TARGET_DLX_DLXTARGETMACHINE_H

#include "DLXInstrInfo.h"
#include "DLXSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

namespace llvm {

class Module;

class DLXTargetMachine : public CodeGenTargetMachineImpl {
  DLXSubtarget Subtarget;
  // std::unique_ptr<TargetLoweringObjectFile> TLOF;

  // NOTE: fields from the documentation
  // const DataLayout DataLayout;
  // DLXInstrInfo InstrInfo;
  // TargetFrameInfo FrameInfo;

  DLXTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                   StringRef FS, const TargetOptions &Options,
                   std::optional<Reloc::Model> RM,
                   std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                   bool JIT);
  ~DLXTargetMachine() override;

  const DLXSubtarget *
  getSubtargetImpl(const llvm::Function & /*Fn*/) const override {
    return &Subtarget;
  }

  TargetTransformInfo getTargetTransformInfo(const Function &F) const override;

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  // TargetLoweringObjectFile *getObjFileLowering() const override {
  //   return TLOF.get();
  // }

  MachineFunctionInfo *
  createMachineFunctionInfo(BumpPtrAllocator &Allocator, const Function &F,
                            const TargetSubtargetInfo *STI) const override;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_DLX_DLXTARGETMACHINE_H
