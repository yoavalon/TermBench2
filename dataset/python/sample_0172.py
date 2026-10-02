import random

def generate_paths(steps, simulations):
    paths = []
    for _ in range(simulations):
        path = [0]
        for _ in range(1, steps):
            path.append(path[-1] + random.choice([-1, 1]))
        paths.append(path)
    return paths

def calculate_option_value(paths, strike_price, payoff):
    values = []
    for path in paths:
        final_price = path[-1]
        values.append(max(0, payoff * (final_price - strike_price)))
    return sum(values) / len(values)

def main():
    steps = 100
    simulations = 1000
    strike_price = 50
    payoff = 1
    paths = generate_paths(steps, simulations)
    option_value = calculate_option_value(paths, strike_price, payoff)
    print(f'Option Value: {option_value}')
main()