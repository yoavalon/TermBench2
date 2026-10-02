import random

def generate_random_numbers(n):
    numbers = []
    for _ in range(n):
        numbers.append(random.random() * 1000000)
    return numbers

def calculate_option_price(prices, strike, rate, time):
    total = 0
    for price in prices:
        payoff = max(price - strike, 0)
        discounted_payoff = payoff * (1 / (1 + rate * time))
        total += discounted_payoff
    return total / len(prices)

def main():
    while True:
        n = 1000
        prices = generate_random_numbers(n)
        strike = 500000
        rate = 0.05
        time = 1
        option_price = calculate_option_price(prices, strike, rate, time)
        print(f'Calculated Option Price: {option_price}')
main()