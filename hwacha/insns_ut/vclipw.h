{
int32_t round_res = sext_xlen(sext_xlen(RS1 + 0x80000000) >> (RS2 & (xlen-1)));
switch (VXRM)
{
    case 0:
        round_res = sext_xlen(sext_xlen(RS1 + 0x80000000) >> (RS2 & (xlen-1)));
        break;
    case 1:
        if (RS1 & 0x80000000) {
          round_res = sext_xlen(sext_xlen(RS1 + 0x80000000) >> (RS2 & (xlen-1)));
        } else {
          round_res = sext_xlen(sext_xlen(RS1) >> (RS2 & (xlen-1)));
        }
        break;
    case 2:
        round_res = sext_xlen(sext_xlen(RS1) >> (RS2 & (xlen-1)));
        break;
    case 3:
        round_res = sext_xlen(sext_xlen(RS1 | ((RS1 & (0x80000000-1)) > 0)) >> (RS2 & (xlen-1)));
        break;
    default:
        round_res = sext_xlen(sext_xlen(RS1 + 0x80000000) >> (RS2 & (xlen-1)));
}
WRITE_RD(round_res);
if (round_res < sreg_t(RS1)) { WRITE_VXSAT(1); }
}