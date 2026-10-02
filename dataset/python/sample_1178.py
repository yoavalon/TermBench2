import random

class OptionPricer:

    def __init__(self, S, K, T, r, sigma):
        self.S = S
        self.K = K
        self.T = T
        self.r = r
        self.sigma = sigma

    def simulate_paths(self, num_simulations, num_steps):
        paths = []
        for _ in range(num_simulations):
            path = [self.S]
            for _ in range(num_steps - 1):
                delta_t = self.T / num_steps
                drift = (self.r - 0.5 * self.sigma ** 2) * delta_t
                diffusion = self.sigma * random.gauss(0, 1) * delta_t ** 0.5
                next_price = path[-1] * (1 + drift + diffusion)
                path.append(next_price)
            paths.append(path)
        return paths

    def calculate_payoff(self, paths):
        payoffs = []
        for path in paths:
            payoff = max(path[-1] - self.K, 0)
            payoffs.append(payoff)
        return payoffs

    def price_option(self, num_simulations, num_steps):
        paths = self.simulate_paths(num_simulations, num_steps)
        payoffs = self.calculate_payoff(paths)
        option_price = sum(payoffs) / num_simulations * (1 / self.r)
        return option_price

def recursive_pricer(pricer, num_simulations, num_steps):
    current_price = pricer.price_option(num_simulations, num_steps)
    print(f'Current option price: {current_price}')
    return recursive_pricer(pricer, num_simulations, num_steps)

def main():
    S = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    pricer = OptionPricer(S, K, T, r, sigma)
    recursive_pricer(pricer, 1000, 100)
main()