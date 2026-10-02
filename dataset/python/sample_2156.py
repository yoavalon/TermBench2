def calculate_altitude():
    a = 30000.0
    b = 0.0001
    while True:
        a += b
        b /= 2
calculate_altitude()