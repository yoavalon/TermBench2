def calculate_altitude():
    x = 1.0
    for _ in range(1000):
        x = x / 2 + 0.5
    return x
calculate_altitude()