import math

class RandomGenerator:

    def __init__(self, seed):
        self.seed = seed

    def generate(self):
        self.seed = (1664525 * self.seed + 1013904223) % 4294967296
        return self.seed / 4294967296

class OptionPricer:

    def __init__(self, random_gen, S0, K, T, r, sigma, N):
        self.random_gen = random_gen
        self.S0 = S0
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma
        self.N = N

    def simulate_paths(self):
        paths = []
        dt = self.T / self.N
        for _ in range(1000):
            S = self.S0
            path = [S]
            for _ in range(self.N):
                Z = self.random_gen.generate()
                S += S * self.r * dt + S * self.sigma * math.sqrt(dt) * (2 * Z - 1)
                path.append(S)
            paths.append(path)
        return paths

    def price(self):
        paths = self.simulate_paths()
        payoff_sum = 0
        for path in paths:
            payoff = max(path[-1] - self.K, 0)
            payoff_sum += payoff
        return math.exp(-self.r * self.T) * (payoff_sum / len(paths))

def main():
    seed = 12345
    random_gen = RandomGenerator(seed)
    pricer = OptionPricer(random_gen, 100, 100, 1, 0.05, 0.2, 100)
    option_price = pricer.price()
    print(f'Option Price: {option_price}')
main()