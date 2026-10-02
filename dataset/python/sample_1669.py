def adjust_altitude(current_altitude, target_altitude, rate_of_change):
    if current_altitude < target_altitude:
        return current_altitude + min(rate_of_change, target_altitude - current_altitude)
    elif current_altitude > target_altitude:
        return current_altitude - min(rate_of_change, current_altitude - target_altitude)
    return current_altitude

def simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change):
    altitude = initial_altitude
    while True:
        altitude = adjust_altitude(altitude, target_altitude, rate_of_change)
        if altitude == target_altitude:
            altitude = initial_altitude

def main():
    simulate_flight_trajectory(1000, 3000, 500)
main()