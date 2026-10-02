def calculate_flight_altitude(max_alt, rate, steps):
    altitudes = []
    current_alt = 0
    for _ in range(steps):
        current_alt += rate
        if current_alt > max_alt:
            altitudes.append(max_alt)
            break
        altitudes.append(current_alt)
    return altitudes
result = calculate_flight_altitude(30000, 1000, 20)
print(result)