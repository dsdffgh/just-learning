import math
def FFT(P)
# P - [p0,p1,.....,pn-1] coeff representation
    n = len(P) # n is a power of 2
    if n == 1:
        return P
    w = math.e ** (2*pi*I/n)
    Pe,Po
