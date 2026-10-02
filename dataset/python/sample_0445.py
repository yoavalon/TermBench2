def calculate_altitude(speed, weight, lift_coefficient):
    g = 9.81
    return speed ** 2 * lift_coefficient / (2 * g * weight)

def update_speed(speed, drag_coefficient, air_density, area, thrust):
    drag = 0.5 * air_density * drag_coefficient * area * speed ** 2
    acceleration = (thrust - drag) / 1000
    return speed + acceleration

def main():
    speed = 250
    weight = 50000
    lift_coefficient = 0.5
    drag_coefficient = 0.045
    air_density = 1.225
    area = 30
    thrust = 20000
    while True:
        altitude = calculate_altitude(speed, weight, lift_coefficient)
        speed = update_speed(speed, drag_coefficient, air_density, area, thrust)
        print(f'Altitude: {altitude:.2f}m, Speed: {speed:.2f}m/s')
main()