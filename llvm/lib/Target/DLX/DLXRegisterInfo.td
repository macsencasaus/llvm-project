// include "llvm/Target/Target.td"

class DLXReg<bits<5> num, string n, list<Register> subregs = []>
  : Register<n> {
  field bits<5> Num;
  let Num = num;
  let Namespace = "DLX";
  let SubRegs = subregs;
}

let Namespace = "Lanai" in {
  def sub_32 : SubRegIndex<32>;
}

// All registers
foreach i = 0-31 in {
  def R#i : DLXReg<i, "r"#1>;
}

// Register aliases (probably don't want this)
let SubRegIndices = [sub_32] in {
  def PC  : DLXReg< 28,  "fp",  [R28]>; // frame pointer
  def SP  : DLXReg< 29,  "sp",  [R29]>; // stack pointer
  def DO  : DLXReg< 30,  "do",  [R30]>; // data offset
}

// status register
def SR : DLXReg< 0, "sw">;

def GPR : RegisterClass<"DLX",
                        /* regtypes */  [i32],
                        /* alignment */ 32,
                        /* reglist */   (sequence "R%i", 0, 31)>;

// Condition code register class
def CCR : RegisterClass<"DLX", [i32], 32, (add SR)> {
  let CopyCost = -1; // Don't allow copying of status registers
  let isAllocatable = 0;
}
