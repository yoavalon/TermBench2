def update_altitude(altitude, rate, limit):
    if altitude + rate > limit:
        return limit
    return altitude + rate

def simulate_flight(initial_altitude, rate, limit):
    altitude = initial_altitude
    while True:
        altitude = update_altitude(altitude, rate, limit)
        print(f'Current Altitude: {altitude}')
        if altitude == limit:
            altitude = initial_altitude

def main():
    initial_altitude = 10000
    rate = 1000
    limit = 35000
    simulate_flight(initial_altitude, rate, limit)
main()