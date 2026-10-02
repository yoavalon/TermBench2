def calculate_altitude_profile(initial_alt, rate, steps):
    altitudes = []
    current_alt = initial_alt
    for _ in range(steps):
        altitudes.append(current_alt)
        current_alt += rate
    return altitudes
calculate_altitude_profile(3000, 500, 10)