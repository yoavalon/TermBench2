def calculate_altitude_profile(initial_altitude, rate_of_change, steps):
    altitude_profile = []
    current_altitude = initial_altitude
    for _ in range(steps):
        altitude_profile.append(current_altitude)
        current_altitude += rate_of_change
    return altitude_profile

def analyze_flight_data(altitude_profile):
    max_altitude = max(altitude_profile)
    min_altitude = min(altitude_profile)
    average_altitude = sum(altitude_profile) / len(altitude_profile)
    return (max_altitude, min_altitude, average_altitude)

def main():
    initial_altitude = 30000
    rate_of_change = 500
    steps = 10
    altitude_profile = calculate_altitude_profile(initial_altitude, rate_of_change, steps)
    max_altitude, min_altitude, average_altitude = analyze_flight_data(altitude_profile)
    print(max_altitude, min_altitude, average_altitude)
main()