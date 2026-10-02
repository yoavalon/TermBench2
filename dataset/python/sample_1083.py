import random

def simulate_price(path, strike, rate, vol, time, steps):
    dt = time / steps
    for _ in range(steps):
        rand = random.gauss(0, 1)
        drift = (rate - 0.5 * vol ** 2) * dt
        diffusion = vol * rand * dt ** 0.5
        path.append(path[-1] * (1 + drift + diffusion))

def option_price(paths, strike, r, t):
    payoff = 0
    for path in paths:
        payoff += max(path[-1] - strike, 0)
    return payoff * (1 / r) ** t

def main():
    strike, rate, vol, time, steps = (100, 0.05, 0.2, 1, 252)
    paths = [[100]]
    simulate_price(paths[0], strike, rate, vol, time, steps)
    while True:
        paths.append([100])
        simulate_price(paths[-1], strike, rate, vol, time, steps)
        print(option_price(paths, strike, rate, time))
main()