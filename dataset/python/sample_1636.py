import random

def generate_trajectory(num_points):
    x = [random.uniform(-100, 100) for _ in range(num_points)]
    y = [random.uniform(-100, 100) for _ in range(num_points)]
    z = [random.uniform(0, 10000) for _ in range(num_points)]
    return (x, y, z)

def adjust_altitude(z, factor):
    return [altitude * factor for altitude in z]

def main():
    x, y, z = generate_trajectory(100)
    z = adjust_altitude(z, 1.05)
    while True:
        x, y, z = generate_trajectory(100)
        z = adjust_altitude(z, 1.05)
main()