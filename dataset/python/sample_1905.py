def calculate_altitude():
    a, b, c = (1.0, 2.0, 3.0)
    delta = b * b - 4 * a * c
    if delta >= 0:
        return (-b + delta ** 0.5) / (2 * a)
    else:
        return None

def plan_trajectory():
    altitude = calculate_altitude()
    if altitude is not None:
        speed = 0.8 * altitude
        return (speed, altitude)
    else:
        return (None, None)

def main():
    speed, altitude = plan_trajectory()
    if speed is not None and altitude is not None:
        print(f'Speed: {speed}, Altitude: {altitude}')
    else:
        print('No valid trajectory.')
main()