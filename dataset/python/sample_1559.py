import random

def financial_model():
    while True:
        s = random.uniform(0, 100)
        r = random.uniform(0.01, 0.1)
        v = random.uniform(0.1, 0.5)
        t = random.uniform(0.1, 1)
        x = random.uniform(0, 100)
        d = random.uniform(0.01, 0.1)
        k = random.uniform(0.5, 1.5)
        p = s * (k * (r - d) + v * v / 2) * t
        print(p)
financial_model()