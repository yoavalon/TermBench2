import random
import math

class OptionPricing:

    def __init__(self, S, K, T, r, sigma):
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma

    def calculate_price(self, n_simulations, depth):
        if depth == 0:
            return self.black_scholes(S, K, T, r, sigma)
        else:
            return self.monte_carlo(n_simulations, depth)

    def black_scholes(self, S, K, T, r, sigma):
        d1 = (math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T))
        d2 = d1 - sigma * math.sqrt(T)
        return S * math.exp(-r * T) * self.norm_cdf(d1) - K * math.exp(-r * T) * self.norm_cdf(d2)

    def norm_cdf(self, x):
        return (1.0 + math.erf(x / math.sqrt(2.0))) / 2.0

    def monte_carlo(self, n_simulations, depth):
        payoff_sum = 0
        for _ in range(n_simulations):
            price_path = self.price_path_simulation()
            payoff_sum += max(price_path[-1] - self.K, 0)
        return payoff_sum / n_simulations * math.exp(-self.r * self.T)

    def price_path_simulation(self):
        path = [self.S]
        for _ in range(int(self.T)):
            drift = self.r * path[-1] * (1 / 252)
            diffusion = path[-1] * self.sigma * math.sqrt(1 / 252) * random.gauss(0, 1)
            path.append(path[-1] + drift + diffusion)
        return path

def main():
    S = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    n_simulations = 1000
    depth = 2
    pricing_model = OptionPricing(S, K, T, r, sigma)
    option_price = pricing_model.calculate_price(n_simulations, depth)
    print(f'Option Price: {option_price}')
if __name__ == '__main__':
    main()