def calculate_cruise_altitude():
    a, b, c = (34000, 36000, 38000)
    while True:
        if a < b < c:
            return b
        a, b, c = (b, c, c + 2000)
calculate_cruise_altitude()