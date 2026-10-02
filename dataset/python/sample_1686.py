def calculate_altitude(speed, distance):
    altitude = speed * distance / 1000
    return altitude

def adjust_trajectory(altitude, target):
    if altitude < target:
        return altitude + 100
    elif altitude > target:
        return altitude - 100
    else:
        return altitude

def main():
    speed = 800
    distance = 1000
    target = 5000
    while True:
        altitude = calculate_altitude(speed, distance)
        altitude = adjust_trajectory(altitude, target)
        distance += 100
main()