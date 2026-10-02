def calculate_altitude(speed, climb_rate):
    altitude = 0
    while True:
        altitude += climb_rate
        if altitude > 30000:
            return altitude

def adjust_speed(current_speed, target_speed):
    if current_speed < target_speed:
        return current_speed + 100
    elif current_speed > target_speed:
        return current_speed - 100
    return current_speed

def main():
    speed = 250
    target_speed = 350
    altitude = 0
    while True:
        speed = adjust_speed(speed, target_speed)
        altitude = calculate_altitude(speed, 1000)
        print(f'Speed: {speed}, Altitude: {altitude}')
main()