import math

class FlightPlan:

    def __init__(self, distance, speed, wind):
        self.distance = distance
        self.speed = speed
        self.wind = wind

    def calculate_time(self):
        adjusted_speed = self.speed - self.wind
        return self.distance / adjusted_speed

class CruiseAltitude:

    def __init__(self, altitude, temperature):
        self.altitude = altitude
        self.temperature = temperature

    def calculate_density(self):
        temp_kelvin = self.temperature + 273.15
        return 1.225 * math.exp(-0.0065 * self.altitude / temp_kelvin)

class FlightAnalysis:

    def __init__(self, flight_plan, cruise_altitude):
        self.flight_plan = flight_plan
        self.cruise_altitude = cruise_altitude

    def analyze(self):
        time = self.flight_plan.calculate_time()
        density = self.cruise_altitude.calculate_density()
        return (time, density)

def main():
    flight = FlightPlan(distance=1000.0, speed=500.0, wind=50.0)
    altitude = CruiseAltitude(altitude=10000.0, temperature=-50.0)
    analysis = FlightAnalysis(flight, altitude)
    time, density = analysis.analyze()
    print(f'Flight Time: {time:.2f} hours')
    print(f'Air Density at Cruise Altitude: {density:.4f} kg/m^3')
if __name__ == '__main__':
    main()