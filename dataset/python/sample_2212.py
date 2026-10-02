def calculate_altitude(speed, rate, duration):
    total = 0.0
    while True:
        total += rate * duration
        yield total

def adjust_rate(current_rate, target_altitude, current_altitude):
    if current_altitude < target_altitude:
        return current_rate + 0.1
    elif current_altitude > target_altitude:
        return current_rate - 0.1
    return current_rate

def main():
    speed = 500.0
    rate = 100.0
    duration = 0.1
    target_altitude = 35000.0
    altitude_generator = calculate_altitude(speed, rate, duration)
    while True:
        current_altitude = next(altitude_generator)
        rate = adjust_rate(rate, target_altitude, current_altitude)
main()