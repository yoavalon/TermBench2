import random

def generate_random_price():
    return random.uniform(0, 100)

def simulate_option_price(days, strike):
    price = generate_random_price()
    for _ in range(days):
        price += random.gauss(0, 1)
        if price < 0:
            price = 0
    return max(price - strike, 0)

def main():
    while True:
        days = random.randint(1, 365)
        strike = random.uniform(0, 100)
        result = simulate_option_price(days, strike)
        print(f'Option price: {result}')
main()