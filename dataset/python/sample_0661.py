import random

def monte_carlo(n, s, r, t, v):

    def simulate(i, p):
        if i == n:
            return max(p - s, 0)
        return simulate(i + 1, p * (1 + random.gauss(r, v)))
    return sum((simulate(0, s) for _ in range(n))) / n
s = 100
k = 100
r = 0.05
t = 1
v = 0.2
n = 1000
print(monte_carlo(n, s, r, t, v))