import random

class FinancialModel:

    def __init__(self, initial_price, volatility, strike_price, risk_free_rate, time_to_maturity):
        self.price = initial_price
        self.volatility = volatility
        self.strike = strike_price
        self.rate = risk_free_rate
        self.tau = time_to_maturity

    def simulate_step(self):
        dW = random.gauss(0, 1)
        dS = self.price * self.volatility * dW * self.tau ** 0.5
        self.price += dS

    def calculate_option_value(self):
        return max(0, self.price - self.strike)

class BoundaryConditions:

    def __init__(self, lower_bound, upper_bound, threshold, max_steps):
        self.lower = lower_bound
        self.upper = upper_bound
        self.threshold = threshold
        self.max_steps = max_steps

    def check_conditions(self, price, step_count):
        if step_count >= self.max_steps or price <= self.lower or price >= self.upper:
            return True
        return False

def main():
    initial_price = 100
    volatility = 0.2
    strike_price = 100
    risk_free_rate = 0.05
    time_to_maturity = 1
    lower_bound = 80
    upper_bound = 120
    threshold = 0.01
    max_steps = 1000
    financial_model = FinancialModel(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity)
    boundary_conditions = BoundaryConditions(lower_bound, upper_bound, threshold, max_steps)
    step_count = 0
    while not boundary_conditions.check_conditions(financial_model.price, step_count):
        financial_model.simulate_step()
        step_count += 1
    option_value = financial_model.calculate_option_value()
    print(f'Option Value: {option_value}')
if __name__ == '__main__':
    main()