
#include <assert.h>
#include <iostream>
#pragma once

// Output stream
#define os std::cerr
#define ost (os << "\t")

namespace as {

using std::string;

constexpr int t0 = 10;
constexpr int t1 = 12;

constexpr int fp = 11;
constexpr int ip = 12;
constexpr int sp = 13;
constexpr int lr = 14;
constexpr int pc = 15;

string const2str(int imm) { return "#" + std::to_string(imm); }

string reg2str(int r) {
  if (r < 11)
    return "r" + std::to_string(r);
  else
    switch (static_cast<int>(r)) {
    case 11:
      return "fp";
      break;
    case 12:
      return "ip";
      break;
    case 13:
      return "sp";
      break;
    case 14:
      return "lr";
      break;
    case 15:
      return "pc";
      break;
    default:
      return "err" + std::to_string(r);
    }
}

void ldr_label(string dst, string label) {
  ost << "ldr"
      << "\t" << dst << ", =" << label << "\n";
}

void ldr(string dst, string base, string offset) {
  ost << "ldr"
      << "\t" << dst << ", [" << base << ", " << offset << "]\n";
}

void str(string src, string base, string offset) {
  ost << "str"
      << "\t" << src << ", [" << base << ", " << offset << "]\n";
}

void mov(string dst, string src) {
  ost << "mov"
      << "\t" << dst << ", " << src << "\n";
}

void add(string dst, string src1, string src2) {
  ost << "add"
      << "\t" << dst << ", " << src1 << ", " << src2 << "\n";
}

void sub(string dst, string src1, string src2) {
  ost << "sub"
      << "\t" << dst << ", " << src1 << ", " << src2 << "\n";
}

void mul(string dst, string src1, string src2) {
  ost << "mul"
      << "\t" << dst << ", " << src1 << ", " << src2 << "\n";
}

void div(string dst, string src1, string src2) {
  ost << "div"
      << "\t" << dst << ", " << src1 << ", " << src2 << "\n";
}

void cmp(string src1, string src2) {
  ost << "cmp"
      << "\t" << src1 << ", " << src2 << "\n";
}

void bcond(string cond, string label) {
  ost << "b" << cond << "\t" << label << "\n";
}

void b(string label) {
  ost << "b"
      << "\t" << label << "\n";
}

void bl(string label) {
  ost << "bl"
      << "\t" << label << "\n";
}

void bx(string dst) {
  ost << "bx"
      << "\t" << dst << "\n";
}

void push(string reglist) {
  ost << "push"
      << "\t" << reglist << "\n";
}

void pop(string reglist) {
  ost << "pop"
      << "\t" << reglist << "\n";
}
// ARM does not have a separate intruction for modulo operations
// void mod(string dst, string src1, string src2);
} // namespace as