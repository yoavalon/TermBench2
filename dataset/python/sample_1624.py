import random

def simulate_price(step):
    return random.normalvariate(0, step)

def generate_prices(steps, iterations):
    prices = []
    for _ in range(iterations):
        current_price = 0
        for _ in range(steps):
            current_price += simulate_price(0.01)
        prices.append(current_price)
    return prices

def analyze_data(data):
    average = sum(data) / len(data)
    variance = sum(((x - average) ** 2 for x in data)) / len(data)
    return (average, variance)

def main():
    while True:
        steps = 100
        iterations = 1000
        data = generate_prices(steps, iterations)
        average, variance = analyze_data(data)
        print(f'Average: {average}, Variance: {variance}')
main()