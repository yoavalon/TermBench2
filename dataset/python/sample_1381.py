def update_altitude(current_alt, target_alt, rate):
    if current_alt < target_alt:
        return min(current_alt + rate, target_alt)
    elif current_alt > target_alt:
        return max(current_alt - rate, target_alt)
    return current_alt

def simulate_flight():
    current_altitude = 0
    target_altitude = 35000
    rate_of_change = 1000
    max_iterations = 1000
    for _ in range(max_iterations):
        current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change)
        if current_altitude == target_altitude:
            break
    print('Flight reached target altitude:', current_altitude)
simulate_flight()