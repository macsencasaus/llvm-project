include "DLXInstrFormats.td"
include "DLXRegisterInfo.td"

def SDT_DLXCallSeqStart : SDCallSeqStart<[/*stack size*/ SDTCisVT<0, i32>,
                                          /*argument alignment*/ SDTCisVT<1, i32>]>;
def SDT_DLXCallSeqEnd   : SDCallSeqStart<[SDTCisVT<0, i32>, SDTCisVT<1, i32>]>;

def SDT_DLXCall         : SDTypeProfile<0, -1, [SDTCisVT<0, i32>]>;
def SDT_DLXSetFlag      : SDTypeProfile<0,  2, [SDTCisSameAs<0, 1>]>;

def SDT_DLXBrCC         : SDTypeProfile<0,  2, [SDTCisVT<0, OtherVT>,
                                                SDTCisVT<1, i32>]>;

def Call : SDNode<"DLXISD::CALL", SDT_DLXCall,
                  [SDNPHasChain, SDNPOptInGlue, SDNPOutGlue,
                   SDNPVariadic]>;

class ALUr<bits<6> op, string OpcString, SDNode OpNode>
  : InstrF2<op, (outs GPR:$Rc), (ins GPR:$Ra, GPR:$Rb),
            !strconcat(OpcString, "\t$Rc, $Ra, $Rb"),
            [(set i32:$Rc, (OpNode GPR:$Ra, GPR:$Rb))]>;

def ADD : ALUr<0, "add", add>;
def SUB : ALUr<1, "sub", sub>;
def MUL : ALUr<2, "mul", mul>;
def DIV : ALUr<3, "div", sdiv>;
def MOD : ALUr<4, "mod", sdivrem>;

def FADD : ALUr<7,  "fadd", fadd>;
def FSUB : ALUr<8,  "fsub", fsub>;
def FMUL : ALUr<9,  "fmul", fmul>;
def FDIV : ALUr<10, "fdiv", fdiv>;
