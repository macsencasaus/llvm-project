#ifndef LLVM_LIB_TARGET_DLX_DLXINSTRINFO_H
#define LLVM_LIB_TARGET_DLX_DLXINSTRINFO_H

#include "DLXRegisterInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

namespace llvm {

class DLXSubtarget;

class DLXInstrInfo : public TargetInstrInfo {
  // const DLXRegisterInfo RegisterInfo;

public:
  DLXInstrInfo(const DLXSubtarget &STI);
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_DLX_DLXINSTRINFO_H
