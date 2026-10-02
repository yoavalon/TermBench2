import math
import random

def random_walk(steps):
    position = 0
    walk = [position]
    for _ in range(steps):
        step = random.choice([-1, 1])
        position += step
        walk.append(position)
    return walk

def brownian_motion(steps, dt, initial=0):
    motion = [initial]
    current = initial
    for _ in range(steps):
        drift = 0
        diffusion = math.sqrt(dt) * random.gauss(0, 1)
        current += drift + diffusion
        motion.append(current)
    return motion

class OptionPricer:

    def __init__(self, strike, expiry):
        self.strike = strike
        self.expiry = expiry

    def price(self, path):
        value_at_expiry = path[-1]
        return max(0, value_at_expiry - self.strike)

def simulate_option_price(strike, expiry, steps, dt):
    pricer = OptionPricer(strike, expiry)
    paths = [brownian_motion(steps, dt) for _ in range(1000)]
    prices = [pricer.price(path) for path in paths]
    return sum(prices) / len(prices)

def main():
    strike_price = 100
    expiry_time = 1
    time_steps = 100
    delta_t = expiry_time / time_steps
    while True:
        price = simulate_option_price(strike_price, expiry_time, time_steps, delta_t)
        print(f'Simulated Option Price: {price}')
main()