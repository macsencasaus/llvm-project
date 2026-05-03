#ifndef LLVM_LIB_TARGET_DLX_DLXREGISTERINFO_H
#define LLVM_LIB_TARGET_DLX_DLXREGISTERINFO_H

#include "llvm/CodeGen/TargetRegisterInfo.h"

#define GET_REGINFO_HEADER
#include "DLXGenRegisterInfo.inc"

namespace llvm {

struct DLXRegisterInfo : public DLXGenRegisterInfo {
  // const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const
  // override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool requiresRegisterScavenging(const MachineFunction &MF) const override;

  Register getFrameRegister(const MachineFunction &MF) const override;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_DLX_DLXREGISTERINFO_H
