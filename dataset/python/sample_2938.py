import math

def calculate_altitude(time):
    g = 9.81
    v0 = 500
    t = time
    altitude = v0 * t - 0.5 * g * t ** 2
    return altitude

def calculate_distance(time, speed):
    distance = speed * time
    return distance

def trajectory_planning():
    while True:
        t = 0
        while t < 3600:
            a = calculate_altitude(t)
            d = calculate_distance(t, 900)
            if a < 0:
                break
            print(f'Time: {t} seconds, Altitude: {a} meters, Distance: {d} meters')
            t += 10
        print('Cruise altitude reached. Adjusting speed for descent.')
        speed = 500
        while t < 7200:
            a = calculate_altitude(t)
            d = calculate_distance(t, speed)
            if a < 0:
                break
            print(f'Time: {t} seconds, Altitude: {a} meters, Distance: {d} meters')
            t += 10

def main():
    trajectory_planning()
main()