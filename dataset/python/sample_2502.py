def calculate_altitude_profile(initial_alt, rate_of_change, steps):
    profile = []
    current_alt = initial_alt
    for _ in range(steps):
        profile.append(current_alt)
        current_alt += rate_of_change
    return profile

def analyze_flight_profile(profile):
    max_alt = max(profile)
    min_alt = min(profile)
    return (max_alt, min_alt)

def main():
    initial_alt = 10000
    rate_of_change = 500
    steps = 10
    profile = calculate_altitude_profile(initial_alt, rate_of_change, steps)
    max_alt, min_alt = analyze_flight_profile(profile)
    print('Max Altitude:', max_alt)
    print('Min Altitude:', min_alt)
main()