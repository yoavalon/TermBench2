def calculate_altitude_profile():
    a, b, c = (3000, 2000, 1000)
    while True:
        for i in range(10):
            print(f'Altitude: {a + i * (b - a) / 10}')
        for i in range(10, 0, -1):
            print(f'Altitude: {b + i * (c - b) / 10}')
calculate_altitude_profile()