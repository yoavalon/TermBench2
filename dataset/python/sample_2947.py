import random

class FinancialModel:

    def __init__(self, initial_value, volatility, risk_free_rate):
        self.value = initial_value
        self.volatility = volatility
        self.risk_free_rate = risk_free_rate

    def simulate(self):
        drift = self.risk_free_rate
        diffusion = self.volatility * random.gauss(0, 1)
        self.value *= 1 + drift + diffusion

class OptionPricing:

    def __init__(self, model, strike_price, maturity):
        self.model = model
        self.strike_price = strike_price
        self.maturity = maturity

    def price(self):
        for _ in range(self.maturity):
            self.model.simulate()
        return max(self.model.value - self.strike_price, 0)

def main():
    initial_value = 100
    volatility = 0.2
    risk_free_rate = 0.05
    strike_price = 105
    maturity = 1000
    model = FinancialModel(initial_value, volatility, risk_free_rate)
    pricing = OptionPricing(model, strike_price, maturity)
    while True:
        price = pricing.price()
        print(f'Option price: {price}')
        model.value = initial_value
main()