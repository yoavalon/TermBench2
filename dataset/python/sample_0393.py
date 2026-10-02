import random

def simulate_options(prices, days):
    while True:
        for _ in range(days):
            for i in range(len(prices)):
                prices[i] *= 1 + (random.random() - 0.5) * 0.1
        yield prices

def main():
    start_prices = [100, 150, 200]
    days = 5
    for result in simulate_options(start_prices, days):
        print(result)
main()