/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Jul 12 06:46:06 EDT 2009 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 8 -dif -name hb2_8 -include hb.h */

/*
 * This function contains 74 FP additions, 50 FP multiplications,
 * (or, 44 additions, 20 multiplications, 30 fused multiply/add),
 * 77 stack variables, 1 constants, and 32 memory accesses
 */
#include "hb.h"

static void hb2_8(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     INT m;
     for (m = mb, W = W + ((mb - 1) * 6); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 6, MAKE_VOLATILE_STRIDE(rs)) {
	  E Tf, Tg, Tl, Tp, Ti, Tj, T1o, T1u, Tk, T1b, To, T1e, TK, Tq, T13;
	  E TP, T1p, T7, T1h, T1v, TZ, Tv, Tw, Ta, Tx, T1j, TE, TB, Td, Ty;
	  E Th, T1n, T1t;
	  Tf = W[0];
	  Tg = W[2];
	  Tl = W[4];
	  Tp = W[5];
	  Ti = W[1];
	  Th = Tf * Tg;
	  T1n = Tf * Tl;
	  T1t = Tf * Tp;
	  Tj = W[3];
	  {
	       E Tr, T3, Ts, T1f, TO, TL, T6, Tt;
	       {
		    E TM, TN, T4, T5;
		    {
			 E T1, Tn, T2, TJ, Tm;
			 T1 = cr[0];
			 T1o = FMA(Ti, Tp, T1n);
			 T1u = FNMS(Ti, Tl, T1t);
			 Tk = FMA(Ti, Tj, Th);
			 T1b = FNMS(Ti, Tj, Th);
			 Tn = Tf * Tj;
			 T2 = ci[WS(rs, 3)];
			 TM = ci[WS(rs, 7)];
			 TJ = Tk * Tp;
			 Tm = Tk * Tl;
			 To = FNMS(Ti, Tg, Tn);
			 T1e = FMA(Ti, Tg, Tn);
			 Tr = T1 - T2;
			 T3 = T1 + T2;
			 TK = FNMS(To, Tl, TJ);
			 Tq = FMA(To, Tp, Tm);
			 TN = cr[WS(rs, 4)];
		    }
		    T4 = cr[WS(rs, 2)];
		    T5 = ci[WS(rs, 1)];
		    Ts = ci[WS(rs, 5)];
		    T1f = TM - TN;
		    TO = TM + TN;
		    TL = T4 - T5;
		    T6 = T4 + T5;
		    Tt = cr[WS(rs, 6)];
	       }
	       {
		    E TC, TD, Tb, Tc;
		    {
			 E T8, T1g, Tu, T9;
			 T8 = cr[WS(rs, 1)];
			 T13 = TO - TL;
			 TP = TL + TO;
			 T1p = T3 - T6;
			 T7 = T3 + T6;
			 T1g = Ts - Tt;
			 Tu = Ts + Tt;
			 T9 = ci[WS(rs, 2)];
			 TC = ci[WS(rs, 4)];
			 T1h = T1f + T1g;
			 T1v = T1f - T1g;
			 TZ = Tr + Tu;
			 Tv = Tr - Tu;
			 Tw = T8 - T9;
			 Ta = T8 + T9;
			 TD = cr[WS(rs, 7)];
		    }
		    Tb = ci[0];
		    Tc = cr[WS(rs, 3)];
		    Tx = ci[WS(rs, 6)];
		    T1j = TC - TD;
		    TE = TC + TD;
		    TB = Tb - Tc;
		    Td = Tb + Tc;
		    Ty = cr[WS(rs, 5)];
	       }
	  }
	  {
	       E TR, TF, Te, T1w;
	       TR = TB + TE;
	       TF = TB - TE;
	       Te = Ta + Td;
	       T1w = Ta - Td;
	       {
		    E Tz, T1i, T1B, T1x, T1c;
		    Tz = Tx + Ty;
		    T1i = Tx - Ty;
		    T1B = T1w + T1v;
		    T1x = T1v - T1w;
		    T1c = T7 - Te;
		    cr[0] = T7 + Te;
		    {
			 E T1k, T1q, TQ, TA;
			 T1k = T1i + T1j;
			 T1q = T1j - T1i;
			 TQ = Tw + Tz;
			 TA = Tw - Tz;
			 {
			      E T1y, T1C, T1m, T1d;
			      T1y = T1o * T1x;
			      T1C = Tk * T1B;
			      T1m = T1e * T1c;
			      T1d = T1b * T1c;
			      {
				   E T1z, T1r, T1l, TG, T14;
				   T1z = T1p + T1q;
				   T1r = T1p - T1q;
				   T1l = T1h - T1k;
				   ci[0] = T1h + T1k;
				   TG = TA + TF;
				   T14 = TA - TF;
				   {
					E T10, TS, T1s, T1A;
					T10 = TQ + TR;
					TS = TQ - TR;
					ci[WS(rs, 6)] = FMA(T1u, T1r, T1y);
					T1s = T1o * T1r;
					ci[WS(rs, 2)] = FMA(To, T1z, T1C);
					T1A = Tk * T1z;
					ci[WS(rs, 4)] = FMA(T1b, T1l, T1m);
					cr[WS(rs, 4)] = FNMS(T1e, T1l, T1d);
					{
					     E T15, T19, TV, TH;
					     T15 = FMA(KP707106781, T14, T13);
					     T19 = FNMS(KP707106781, T14, T13);
					     TV = FMA(KP707106781, TG, Tv);
					     TH = FNMS(KP707106781, TG, Tv);
					     {
						  E TT, TX, T11, T17;
						  TT = FNMS(KP707106781, TS, TP);
						  TX = FMA(KP707106781, TS, TP);
						  T11 = FNMS(KP707106781, T10, TZ);
						  T17 = FMA(KP707106781, T10, TZ);
						  cr[WS(rs, 6)] = FNMS(T1u, T1x, T1s);
						  cr[WS(rs, 2)] = FNMS(To, T1B, T1A);
						  {
						       E T1a, T16, TU, TI;
						       T1a = Tl * T19;
						       T16 = Tg * T15;
						       TU = TK * TH;
						       TI = Tq * TH;
						       {
							    E TY, TW, T18, T12;
							    TY = Ti * TV;
							    TW = Tf * TV;
							    T18 = Tl * T17;
							    T12 = Tg * T11;
							    ci[WS(rs, 7)] = FMA(Tp, T17, T1a);
							    ci[WS(rs, 3)] = FMA(Tj, T11, T16);
							    ci[WS(rs, 5)] = FMA(Tq, TT, TU);
							    cr[WS(rs, 5)] = FNMS(TK, TT, TI);
							    ci[WS(rs, 1)] = FMA(Tf, TX, TY);
							    cr[WS(rs, 1)] = FNMS(Ti, TX, TW);
							    cr[WS(rs, 7)] = FNMS(Tp, T19, T18);
							    cr[WS(rs, 3)] = FNMS(Tj, T15, T12);
						       }
						  }
					     }
					}
				   }
			      }
			 }
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_CEXP, 1, 1},
     {TW_CEXP, 1, 3},
     {TW_CEXP, 1, 7},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 8, "hb2_8", twinstr, &GENUS, {44, 20, 30, 0} };

void X(codelet_hb2_8) (planner *p) {
     X(khc2hc_register) (p, hb2_8, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc -compact -variables 4 -pipeline-latency 4 -sign 1 -twiddle-log3 -precompute-twiddles -n 8 -dif -name hb2_8 -include hb.h */

/*
 * This function contains 74 FP additions, 44 FP multiplications,
 * (or, 56 additions, 26 multiplications, 18 fused multiply/add),
 * 46 stack variables, 1 constants, and 32 memory accesses
 */
#include "hb.h"

static void hb2_8(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     INT m;
     for (m = mb, W = W + ((mb - 1) * 6); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 6, MAKE_VOLATILE_STRIDE(rs)) {
	  E Tf, Ti, Tg, Tj, Tl, Tp, TP, TR, TF, TG, TH, T15, TL, TT;
	  {
	       E Th, To, Tk, Tn;
	       Tf = W[0];
	       Ti = W[1];
	       Tg = W[2];
	       Tj = W[3];
	       Th = Tf * Tg;
	       To = Ti * Tg;
	       Tk = Ti * Tj;
	       Tn = Tf * Tj;
	       Tl = Th - Tk;
	       Tp = Tn + To;
	       TP = Th + Tk;
	       TR = Tn - To;
	       TF = W[4];
	       TG = W[5];
	       TH = FMA(Tf, TF, Ti * TG);
	       T15 = FNMS(TR, TF, TP * TG);
	       TL = FNMS(Ti, TF, Tf * TG);
	       TT = FMA(TP, TF, TR * TG);
	  }
	  {
	       E T7, T1f, T1i, Tw, TI, TW, T18, TM, Te, T19, T1a, TD, TJ, TZ, T12;
	       E TN, Tm, TE;
	       {
		    E T3, TU, Tv, TV, T6, T16, Ts, T17;
		    {
			 E T1, T2, Tt, Tu;
			 T1 = cr[0];
			 T2 = ci[WS(rs, 3)];
			 T3 = T1 + T2;
			 TU = T1 - T2;
			 Tt = ci[WS(rs, 5)];
			 Tu = cr[WS(rs, 6)];
			 Tv = Tt - Tu;
			 TV = Tt + Tu;
		    }
		    {
			 E T4, T5, Tq, Tr;
			 T4 = cr[WS(rs, 2)];
			 T5 = ci[WS(rs, 1)];
			 T6 = T4 + T5;
			 T16 = T4 - T5;
			 Tq = ci[WS(rs, 7)];
			 Tr = cr[WS(rs, 4)];
			 Ts = Tq - Tr;
			 T17 = Tq + Tr;
		    }
		    T7 = T3 + T6;
		    T1f = TU + TV;
		    T1i = T17 - T16;
		    Tw = Ts + Tv;
		    TI = T3 - T6;
		    TW = TU - TV;
		    T18 = T16 + T17;
		    TM = Ts - Tv;
	       }
	       {
		    E Ta, TX, TC, T11, Td, T10, Tz, TY;
		    {
			 E T8, T9, TA, TB;
			 T8 = cr[WS(rs, 1)];
			 T9 = ci[WS(rs, 2)];
			 Ta = T8 + T9;
			 TX = T8 - T9;
			 TA = ci[WS(rs, 4)];
			 TB = cr[WS(rs, 7)];
			 TC = TA - TB;
			 T11 = TA + TB;
		    }
		    {
			 E Tb, Tc, Tx, Ty;
			 Tb = ci[0];
			 Tc = cr[WS(rs, 3)];
			 Td = Tb + Tc;
			 T10 = Tb - Tc;
			 Tx = ci[WS(rs, 6)];
			 Ty = cr[WS(rs, 5)];
			 Tz = Tx - Ty;
			 TY = Tx + Ty;
		    }
		    Te = Ta + Td;
		    T19 = TX + TY;
		    T1a = T10 + T11;
		    TD = Tz + TC;
		    TJ = TC - Tz;
		    TZ = TX - TY;
		    T12 = T10 - T11;
		    TN = Ta - Td;
	       }
	       cr[0] = T7 + Te;
	       ci[0] = Tw + TD;
	       Tm = T7 - Te;
	       TE = Tw - TD;
	       cr[WS(rs, 4)] = FNMS(Tp, TE, Tl * Tm);
	       ci[WS(rs, 4)] = FMA(Tp, Tm, Tl * TE);
	       {
		    E TQ, TS, TK, TO;
		    TQ = TI + TJ;
		    TS = TN + TM;
		    cr[WS(rs, 2)] = FNMS(TR, TS, TP * TQ);
		    ci[WS(rs, 2)] = FMA(TP, TS, TR * TQ);
		    TK = TI - TJ;
		    TO = TM - TN;
		    cr[WS(rs, 6)] = FNMS(TL, TO, TH * TK);
		    ci[WS(rs, 6)] = FMA(TH, TO, TL * TK);
	       }
	       {
		    E T1h, T1l, T1k, T1m, T1g, T1j;
		    T1g = KP707106781 * (T19 + T1a);
		    T1h = T1f - T1g;
		    T1l = T1f + T1g;
		    T1j = KP707106781 * (TZ - T12);
		    T1k = T1i + T1j;
		    T1m = T1i - T1j;
		    cr[WS(rs, 3)] = FNMS(Tj, T1k, Tg * T1h);
		    ci[WS(rs, 3)] = FMA(Tg, T1k, Tj * T1h);
		    cr[WS(rs, 7)] = FNMS(TG, T1m, TF * T1l);
		    ci[WS(rs, 7)] = FMA(TF, T1m, TG * T1l);
	       }
	       {
		    E T14, T1d, T1c, T1e, T13, T1b;
		    T13 = KP707106781 * (TZ + T12);
		    T14 = TW - T13;
		    T1d = TW + T13;
		    T1b = KP707106781 * (T19 - T1a);
		    T1c = T18 - T1b;
		    T1e = T18 + T1b;
		    cr[WS(rs, 5)] = FNMS(T15, T1c, TT * T14);
		    ci[WS(rs, 5)] = FMA(T15, T14, TT * T1c);
		    cr[WS(rs, 1)] = FNMS(Ti, T1e, Tf * T1d);
		    ci[WS(rs, 1)] = FMA(Ti, T1d, Tf * T1e);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_CEXP, 1, 1},
     {TW_CEXP, 1, 3},
     {TW_CEXP, 1, 7},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 8, "hb2_8", twinstr, &GENUS, {56, 26, 18, 0} };

void X(codelet_hb2_8) (planner *p) {
     X(khc2hc_register) (p, hb2_8, &desc);
}
#endif				/* HAVE_FMA */
