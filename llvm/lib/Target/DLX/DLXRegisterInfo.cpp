#include "DLXRegisterInfo.h"

using namespace llvm;

#define GET_REGINFO_ENUM
#define GET_REGINFO_TARGET_DESC
#include "DLXGenRegisterInfo.inc"

BitVector DLXRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());

  Reserved.set(DLX::R0);
  Reserved.set(DLX::R28);
  Reserved.set(DLX::R29);
  Reserved.set(DLX::R30);

  return Reserved;
}

Register DLXRegisterInfo::getFrameRegister(const MachineFunction &) const {
  return DLX::R28;
}

bool DLXRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &) const {
  return true;
}
