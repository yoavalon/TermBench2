def generate_flight_trajectory():
    x = 0
    y = 0
    v = 100
    g = 9.81
    while True:
        y = v * x - 0.5 * g * x ** 2
        print(f'Time: {x}, Altitude: {y}')
        x += 1
generate_flight_trajectory()