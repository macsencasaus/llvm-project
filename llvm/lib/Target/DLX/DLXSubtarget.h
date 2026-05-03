#ifndef LLVM_LIB_TARGET_DLX_DLXSUBTARGET_H
#define LLVM_LIB_TARGET_DLX_DLXSUBTARGET_H

#include "DLXInstrInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include "llvm/Target/TargetOptions.h"

namespace llvm {

class DLXSubtarget : public TargetSubtargetInfo {
public:
  DLXSubtarget(const Triple &TargetTriple, StringRef Cpu,
               StringRef FeatureString, const TargetMachine &TM,
               const TargetOptions &Options, CodeModel::Model CodeModel,
               CodeGenOptLevel OptLevel);

  const TargetRegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  };

private:
  DLXInstrInfo InstrInfo;
};
} // namespace llvm

#endif // LLVM_LIB_TARGET_DLX_DLXSUBTARGET_H
