def calculate_cruise_altitude(speed, temperature):
    a = 1.0287
    b = -10.911
    c = 260370
    return a * speed + b * temperature + c

def plan_trajectory(altitudes, target):
    total = 0.0
    for altitude in altitudes:
        total += altitude
    average = total / len(altitudes)
    return average - target

def main():
    speeds = [800.5, 900.3, 750.8]
    temperatures = [15.2, 14.8, 16.0]
    altitudes = [calculate_cruise_altitude(s, t) for s, t in zip(speeds, temperatures)]
    target_altitude = 35000.0
    adjustment = plan_trajectory(altitudes, target_altitude)
    print(f'Adjustment needed: {adjustment:.2f} meters')
main()