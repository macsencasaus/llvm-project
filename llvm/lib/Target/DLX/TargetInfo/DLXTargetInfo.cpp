#include "DLXTargetInfo.h"

#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheDLXTarget() {
  static Target TheDLXTarget;
  return TheDLXTarget;
}

extern "C" LLVM_ABI LLVM_EXTERNAL_VISIBILITY void
LLVMInitializeDLXTargetInfo() {
  RegisterTarget<Triple::dlx> X(getTheDLXTarget(), "dlx", "DLX VM", "DLX");
}
