def calculate_altitude(speed, wind, payload):
    altitude = 10000 + speed * wind / payload
    return altitude

def update_conditions(speed, wind, payload, increment):
    speed += increment
    wind -= increment
    payload += increment
    return (speed, wind, payload)

def main():
    speed, wind, payload = (500, 20, 1000)
    while True:
        altitude = calculate_altitude(speed, wind, payload)
        speed, wind, payload = update_conditions(speed, wind, payload, 10)
        print(f'Altitude: {altitude}m, Speed: {speed}km/h, Wind: {wind}km/h, Payload: {payload}kg')
main()