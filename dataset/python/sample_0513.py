class FlightPath:

    def __init__(self, start_altitude, target_altitude, rate_of_climb):
        self.altitude = start_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb

    def climb(self):
        self.altitude += self.rate_of_climb
        if self.altitude > self.target_altitude:
            self.altitude = self.target_altitude

    def get_status(self):
        return (self.altitude, self.target_altitude)

class CruiseAltitude:

    def __init__(self, altitude, max_speed, wind_speed):
        self.altitude = altitude
        self.max_speed = max_speed
        self.wind_speed = wind_speed

    def adjust_speed(self):
        self.max_speed = self.max_speed - self.wind_speed * 0.5

    def get_speed(self):
        return self.max_speed

def main():
    flight = FlightPath(1000, 35000, 100)
    cruise = CruiseAltitude(35000, 800, 20)
    while True:
        flight.climb()
        cruise.adjust_speed()
        current_alt, target_alt = flight.get_status()
        current_speed = cruise.get_speed()
        if current_alt == target_alt:
            print(f'Reached target altitude: {current_alt}')
            print(f'Cruise speed adjusted to: {current_speed}')
        else:
            print(f'Current altitude: {current_alt}, Target altitude: {target_alt}')
            print(f'Current speed: {current_speed}')
main()