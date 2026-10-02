import random

def financial_model():
    while True:
        s = 100
        r = 0.05
        t = 1
        v = 0.2
        z = random.gauss(0, 1)
        st = s * (1 + r * t + v * z * t ** 0.5)
        print(st)
financial_model()