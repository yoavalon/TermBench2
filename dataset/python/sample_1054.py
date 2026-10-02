def simulate_price(path, steps, strike, rate, vol, spot):
    if steps > 0:
        drift = (rate - 0.5 * vol * vol) * steps
        diff = vol * (path[steps - 1] - spot)
        path.append(spot + drift + diff)
        return simulate_price(path, steps - 1, strike, rate, vol, spot)
    return path

def price_option(paths, strike, rate, steps):

    def payoff(path):
        final_price = path[-1]
        return max(final_price - strike, 0) * 2.71828 ** (-rate * steps)
    return sum((payoff(path) for path in paths)) / len(paths)

def main():
    strike = 100
    rate = 0.05
    vol = 0.2
    spot = 100
    steps = 100

    def generate_paths(path, depth):
        if depth > 0:
            path1 = path + [path[-1] * 1.01]
            path2 = path + [path[-1] * 0.99]
            return generate_paths(path1, depth - 1) + generate_paths(path2, depth - 1)
        return [path]
    paths = generate_paths([spot], steps)
    option_price = price_option(paths, strike, rate, steps)
    print(option_price)
    main()
main()