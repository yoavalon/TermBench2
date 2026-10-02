import random

def generate_prices(num_days, initial_price, volatility):
    prices = [initial_price]
    for _ in range(num_days - 1):
        change = random.gauss(0, volatility)
        new_price = prices[-1] * (1 + change)
        prices.append(new_price)
    return prices

def calculate_payoffs(prices, strike_price, call_or_put):
    payoffs = []
    for price in prices:
        if call_or_put == 'call':
            payoff = max(price - strike_price, 0)
        else:
            payoff = max(strike_price - price, 0)
        payoffs.append(payoff)
    return payoffs

def monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity):
    total_payoff = 0
    for _ in range(num_simulations):
        prices = generate_prices(num_days, initial_price, volatility)
        payoffs = calculate_payoffs(prices, strike_price, call_or_put)
        discounted_payoff = sum(payoffs) / len(payoffs) * (1 + risk_free_rate) ** (-time_to_maturity)
        total_payoff += discounted_payoff
    return total_payoff / num_simulations

def main():
    num_simulations = 1000
    num_days = 365
    initial_price = 100
    strike_price = 100
    volatility = 0.2
    call_or_put = 'call'
    risk_free_rate = 0.05
    time_to_maturity = 1
    option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity)
    print(f'Option price: {option_price}')
if __name__ == '__main__':
    main()