%
O32123 (NC Viewer Demo File)
G21 G98
G28 U0 W0
M06 T0101 
M03 S2500
G00 X26 Z2     // REPETITION OF same task in facing no change in diameter , only length changes, now we dont have to write those lines again and again 
G94 X0 Z-0.5 F80
Z-1
Z-1.5
Z-2
G28 U0 W0
M05
M30
%