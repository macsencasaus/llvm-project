#include "DLXTargetMachine.h"

using namespace llvm;

static Reloc::Model getEffectiveRelocModel(std::optional<Reloc::Model> RM) {
  return RM.value_or(Reloc::PIC_);
}

DLXTargetMachine::DLXTargetMachine(const Target &T, const Triple &TT,
                                   StringRef Cpu, StringRef FeatureString,
                                   const TargetOptions &Options,
                                   std::optional<Reloc::Model> RM,
                                   std::optional<CodeModel::Model> CodeModel,
                                   CodeGenOptLevel OptLevel, bool JIT)
    : CodeGenTargetMachineImpl(
          T, TT.computeDataLayout(), TT, Cpu, FeatureString, Options,
          getEffectiveRelocModel(RM),
          getEffectiveCodeModel(CodeModel, CodeModel::Medium), OptLevel),
      Subtarget(TT, Cpu, FeatureString, *this, Options, getCodeModel(),
                OptLevel)
// TODO:
/* ,TLOF(new LanaiTargetObjectFile()) */
{
  initAsmInfo();
}
