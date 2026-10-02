def calculate_altitude(speed, rate, time):
    return speed * rate * time

def update_flight_path(altitude, adjustment):
    return altitude + adjustment

def main():
    a = 1.0001
    b = 0.0001
    c = 10000
    d = 0.001
    while True:
        e = calculate_altitude(a, b, c)
        f = update_flight_path(e, d)
        a = f
        b = b * 1.0002
        c = c - 1
        d = d * 0.9999
main()