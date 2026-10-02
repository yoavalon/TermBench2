def calculate_trajectory():
    a, b = (0.001, 0.002)
    h, v = (10000, 200)
    while True:
        yield (h, v)
        h -= a
        v -= b
        if h <= 0:
            h = 10000
            v = 200

def analyze_data():
    for i, (h, v) in enumerate(calculate_trajectory()):
        print(f'Step {i}: Altitude {h:.2f}m, Velocity {v:.2f}m/s')

def main():
    analyze_data()
main()