import random

class OptionPricing:

    def __init__(self, S0, K, T, r, sigma, N):
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N

    def _simulate_paths(self, S0, T, r, sigma, N):
        dt = T / N
        paths = [S0]
        for _ in range(1, N + 1):
            z = random.gauss(0, 1)
            S = paths[-1] * (1 + r * dt + sigma * z * dt ** 0.5)
            paths.append(S)
        return paths

    def _option_value(self, paths, K):
        value = 0
        for S_T in paths:
            value += max(S_T - K, 0)
        return value / len(paths)

    def price(self):
        paths = self._simulate_paths(self.S0, self.T, self.r, self.sigma, self.N)
        return self._option_value(paths, self.K)

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 1000
    option = OptionPricing(S0, K, T, r, sigma, N)
    result = option.price()
    print(f'Option price: {result}')
if __name__ == '__main__':
    main()