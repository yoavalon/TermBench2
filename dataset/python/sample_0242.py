class FlightData:

    def __init__(self, altitude, speed, distance, max_altitude):
        self.altitude = altitude
        self.speed = speed
        self.distance = distance
        self.max_altitude = max_altitude

    def update_altitude(self, new_altitude):
        if new_altitude <= self.max_altitude:
            self.altitude = new_altitude
        else:
            self.altitude = self.max_altitude

    def update_distance(self, new_distance):
        self.distance = new_distance

class CruisePlanner:

    def __init__(self, flight_data):
        self.flight_data = flight_data

    def calculate_cruise_altitude(self):
        if self.flight_data.speed > 500:
            return min(self.flight_data.altitude + 1000, self.flight_data.max_altitude)
        else:
            return max(self.flight_data.altitude - 1000, 0)

    def adjust_trajectory(self):
        new_altitude = self.calculate_cruise_altitude()
        self.flight_data.update_altitude(new_altitude)
        self.flight_data.update_distance(self.flight_data.distance + 100)

def main():
    flight_data = FlightData(5000, 600, 0, 10000)
    cruise_planner = CruisePlanner(flight_data)
    for _ in range(10):
        cruise_planner.adjust_trajectory()
    print(f'Final Altitude: {flight_data.altitude}')
    print(f'Final Distance: {flight_data.distance}')
main()