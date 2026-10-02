def adjust_altitude(current_alt, target_alt):
    if current_alt < target_alt:
        return current_alt + 1000
    elif current_alt > target_alt:
        return current_alt - 500
    else:
        return current_alt

def simulate_flight():
    alt = 10000
    target = 30000
    while True:
        alt = adjust_altitude(alt, target)
        if alt == target:
            alt = 10000

def main():
    simulate_flight()
main()