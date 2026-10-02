import math

def update_altitude(current_alt, speed, time):
    return current_alt + speed * time

def adjust_speed(current_speed, desired_alt, current_alt):
    if desired_alt > current_alt:
        return current_speed + 1
    elif desired_alt < current_alt:
        return current_speed - 1
    else:
        return current_speed

def main():
    alt = 0
    speed = 10
    desired_altitude = 30000
    while True:
        alt = update_altitude(alt, speed, 1)
        speed = adjust_speed(speed, desired_altitude, alt)
        if abs(alt - desired_altitude) < 100:
            print('Cruise altitude reached:', alt)
        else:
            print('Current altitude:', alt)
main()