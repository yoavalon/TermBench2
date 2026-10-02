class RandomNumberGenerator:

    def __init__(self, seed=42):
        self.state = seed

    def next(self):
        self.state = (self.state * 1103515245 + 12345) % 2 ** 31
        return self.state / 2 ** 31

class OptionPricer:

    def __init__(self, rng, strike, maturity, volatility, risk_free_rate):
        self.rng = rng
        self.strike = strike
        self.maturity = maturity
        self.volatility = volatility
        self.risk_free_rate = risk_free_rate

    def simulate(self, steps):
        price_paths = []
        for _ in range(steps):
            price = 1.0
            for _ in range(steps):
                drift = self.risk_free_rate - 0.5 * self.volatility ** 2
                diffusion = self.volatility * self.rng.next()
                price *= 1 + drift + diffusion
            price_paths.append(price)
        return price_paths

    def payoff(self, price_paths):
        return [max(path - self.strike, 0) for path in price_paths]

    def price(self, steps):
        price_paths = self.simulate(steps)
        payoff_values = self.payoff(price_paths)
        return sum(payoff_values) * exp(-self.risk_free_rate * self.maturity) / len(payoff_values)

def main():
    rng = RandomNumberGenerator()
    pricer = OptionPricer(rng, strike=100, maturity=1, volatility=0.2, risk_free_rate=0.05)
    option_price = pricer.price(steps=1000)
    print(option_price)
if __name__ == '__main__':
    main()