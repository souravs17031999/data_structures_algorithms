﻿%
O32123 (NC Viewer Demo File)
G21 G98
G28 U0 W0
M06 T0101 
M03 S2500
G00 X32 Z5     /RAPID TRANSVERSE TILL THE INITIAL POS
G71 U0.5 R1    / CALL THE CYCLE AND DEFINE EACH TIME U DEPTH AND R RETRACTED
G71 P1 Q7 U0.1 W0.1 F100 / AGAIN CALL IT BY DEFINING P START LINE NUMBER , Q AS LAST LINE NUMBER , U AS X_ALLOWANCE , W AS Z_ALLOWANCE , F FEED RATE
N1 G01 X18 F100   / NOW SIMPLY ON EACH LINE WE HAVE TO JUST GIVE THE COORDINATE STARTING FROM INITIAL ONE TO LAST ONE ONE BY ONE 
N2 G01 Z0
N3 G01 X20 Z-4     / WHEREVER DIAGONAL CUT , GIVE X AND Z BOTH
N4 Z-16            / NO CHANGE IN X SO ONLY DEFINE Z 
N5 G03 X24 Z-20 R4  / NOW THERE IS A RADIAL CUT 
N6 G01 Z-30         / AGAIN NO CHANGE IN X
N7 G01 X32 Z-38    / NOW AGAIN DIAGONAL SO X AND Z BOTH
G70 P1 Q2 F80     / THIS IS FINISHING PASS WHICH WILL AGAIN DEFINE P START LINENO , Q SECOND LINENO. , FEED RATE LITTLE SLOW
G28 U0 W0
M05
M30
%