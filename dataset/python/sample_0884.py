class OptionPricer:

    def __init__(self, strike, spot, vol, rate, div, T):
        self.strike = strike
        self.spot = spot
        self.vol = vol
        self.rate = rate
        self.div = div
        self.T = T

    def d1(self, S, K, T, r, q, sigma):
        return (log(S / K) + (r - q + 0.5 * sigma ** 2) * T) / (sigma * sqrt(T))

    def d2(self, d1, sigma, T):
        return d1 - sigma * sqrt(T)

    def call_price(self, S, K, T, r, q, sigma):
        if T <= 0:
            return max(0, S - K)
        d1_val = self.d1(S, K, T, r, q, sigma)
        d2_val = self.d2(d1_val, sigma, T)
        return S * exp(-q * T) * norm.cdf(d1_val) - K * exp(-r * T) * norm.cdf(d2_val)

class MonteCarloSimulator:

    def __init__(self, pricer, paths, steps):
        self.pricer = pricer
        self.paths = paths
        self.steps = steps

    def simulate(self):
        prices = []
        for _ in range(self.paths):
            price_path = self.pricer.spot
            for _ in range(1, self.steps):
                price_path = self._step(price_path)
            prices.append(price_path)
        return prices

    def _step(self, S):
        dt = self.pricer.T / self.steps
        dS = S * (self.pricer.rate - self.pricer.div) * dt + S * self.pricer.vol * sqrt(dt) * random.gauss(0, 1)
        return S + dS

def main():
    strike = 100
    spot = 100
    vol = 0.2
    rate = 0.05
    div = 0.02
    T = 1
    paths = 1000
    steps = 100
    pricer = OptionPricer(strike, spot, vol, rate, div, T)
    simulator = MonteCarloSimulator(pricer, paths, steps)
    final_prices = simulator.simulate()
    option_value = sum((pricer.call_price(price, strike, T, rate, div, vol) for price in final_prices)) / paths
    print(option_value)
if __name__ == '__main__':
    main()