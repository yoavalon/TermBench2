def update_altitude(current_alt, target_alt, rate):
    if current_alt < target_alt:
        return min(current_alt + rate, target_alt)
    elif current_alt > target_alt:
        return max(current_alt - rate, target_alt)
    return current_alt

def simulate_flight():
    current_alt = 0
    target_alt = 35000
    rate = 500
    while True:
        current_alt = update_altitude(current_alt, target_alt, rate)
        if current_alt == target_alt:
            target_alt = 0
            rate = 100
        else:
            rate = 500
simulate_flight()