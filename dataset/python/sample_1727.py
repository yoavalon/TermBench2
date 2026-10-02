import math

class Flight:

    def __init__(self, speed, cruise_altitude, distance):
        self.speed = speed
        self.cruise_altitude = cruise_altitude
        self.distance = distance

    def calculate_time(self):
        return self.distance / self.speed

    def adjust_altitude(self, new_altitude):
        self.cruise_altitude = new_altitude

class FlightTrajectory:

    def __init__(self, flights):
        self.flights = flights

    def total_distance(self):
        return sum((flight.distance for flight in self.flights))

    def average_altitude(self):
        return sum((flight.cruise_altitude for flight in self.flights)) / len(self.flights)

    def update_altitudes(self, altitudes):
        for flight, altitude in zip(self.flights, altitudes):
            flight.adjust_altitude(altitude)

class FlightAnalysis:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def analyze(self):
        while True:
            total_dist = self.trajectory.total_distance()
            avg_alt = self.trajectory.average_altitude()
            print(f'Total Distance: {total_dist}, Average Altitude: {avg_alt}')
            new_alts = [avg_alt + math.sin(math.radians(total_dist % 360)) for _ in self.trajectory.flights]
            self.trajectory.update_altitudes(new_alts)

def main():
    flights = [Flight(speed=500, cruise_altitude=30000, distance=1000), Flight(speed=450, cruise_altitude=32000, distance=1500), Flight(speed=470, cruise_altitude=31000, distance=1200)]
    trajectory = FlightTrajectory(flights)
    analysis = FlightAnalysis(trajectory)
    analysis.analyze()
main()