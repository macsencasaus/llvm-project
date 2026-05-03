include "llvm/Target/Target.td"

class InstrDLX<dag outs, dag ins, string asmstr, list<dag> pattern>
  : Instruction {
  field bits<32> Inst;
  let Size = 4;

  let Namespace = "DLX";
  let DecoderNamespace = "DLX";

  bits <6> Opcode;
  let Inst{31-26} = Opcode;

  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
}

// Format F1

class InstrF1<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern>
  : InstrDLX<outs, ins, asmstr, pattern> {
  // TODO: add sched

  bits<5> Ra;
  bits<5> Rb;
  bits<16> c;

  let Opcode = op;
  let Inst{25 - 21} = Ra;
  let Inst{20 - 16} = Rb;
  let Inst{15 - 0}  = c;
}

// Format F2

class InstrF2<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern>
  : InstrDLX<outs, ins, asmstr, pattern> {

  bits<5> Ra;
  bits<5> Rb;
  bits<5> Rc;

  let Opcode = op;
  let Inst{25 - 21} = Ra;
  let Inst{20 - 16} = Rb;
  let Inst{15 - 5}  = 0;
  let Inst{4 - 0}   = Rc;
}

// Format F3

class InstrF3<bits<6> op, dag outs, dag ins, string asmstr, list<dag> pattern>
  : InstrDLX<outs, ins, asmstr, pattern> {

  bits<26> c;

  let Opcode = op;
  let Inst{25 - 0} = c;
}
