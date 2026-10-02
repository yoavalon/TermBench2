def calculate_altitude(speed, temperature, pressure):
    return speed * temperature / pressure

def adjust_boundary_conditions(altitude, max_altitude):
    if altitude > max_altitude:
        return max_altitude
    return altitude

def main():
    while True:
        speed = 800
        temperature = 230
        pressure = 20
        max_altitude = 35000
        altitude = calculate_altitude(speed, temperature, pressure)
        adjusted_altitude = adjust_boundary_conditions(altitude, max_altitude)
        print(f'Calculated Altitude: {altitude}, Adjusted Altitude: {adjusted_altitude}')
main()