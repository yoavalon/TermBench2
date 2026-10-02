import math

class Option:

    def __init__(self, strike, maturity):
        self.strike = strike
        self.maturity = maturity

    def payoff(self, spot):
        return max(spot - self.strike, 0)

class MonteCarloPricer:

    def __init__(self, option, initial_price, volatility, risk_free_rate, steps, simulations):
        self.option = option
        self.initial_price = initial_price
        self.volatility = volatility
        self.risk_free_rate = risk_free_rate
        self.steps = steps
        self.simulations = simulations
        self.dt = option.maturity / steps

    def simulate_paths(self):
        paths = [[self.initial_price] for _ in range(self.simulations)]
        for _ in range(1, self.steps):
            for i in range(self.simulations):
                paths[i].append(paths[i][-1] * math.exp((self.risk_free_rate - 0.5 * self.volatility ** 2) * self.dt + self.volatility * math.sqrt(self.dt) * (2 * (random.random() - 0.5))))
        return paths

    def price_option(self):
        paths = self.simulate_paths()
        payoffs = [self.option.payoff(path[-1]) for path in paths]
        return math.exp(-self.risk_free_rate * self.option.maturity) * sum(payoffs) / self.simulations

def main():
    strike = 100
    maturity = 1.0
    initial_price = 100
    volatility = 0.2
    risk_free_rate = 0.05
    steps = 100
    simulations = 1000
    option = Option(strike, maturity)
    pricer = MonteCarloPricer(option, initial_price, volatility, risk_free_rate, steps, simulations)
    price = pricer.price_option()
    print(f'Option price: {price}')
if __name__ == '__main__':
    main()