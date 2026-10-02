class FlightParameters:

    def __init__(self, initial_altitude, cruise_altitude, rate_of_climb, rate_of_descent):
        self.altitude = initial_altitude
        self.cruise_altitude = cruise_altitude
        self.rate_of_climb = rate_of_climb
        self.rate_of_descent = rate_of_descent

    def update_altitude(self, action):
        if action == 'climb':
            self.altitude += self.rate_of_climb
        elif action == 'descend':
            self.altitude -= self.rate_of_descent

    def is_at_cruise(self):
        return self.altitude >= self.cruise_altitude

class BoundaryConditions:

    def __init__(self, min_altitude, max_altitude):
        self.min_altitude = min_altitude
        self.max_altitude = max_altitude

    def is_within_bounds(self, altitude):
        return self.min_altitude <= altitude <= self.max_altitude

    def adjust_boundary(self, altitude):
        if altitude < self.min_altitude:
            return self.min_altitude
        elif altitude > self.max_altitude:
            return self.max_altitude
        return altitude

def flight_control_system(flight, boundaries):
    while True:
        if not boundaries.is_within_bounds(flight.altitude):
            flight.altitude = boundaries.adjust_boundary(flight.altitude)
        if not flight.is_at_cruise():
            action = 'climb' if flight.altitude < flight.cruise_altitude else 'descend'
            flight.update_altitude(action)

def main():
    flight = FlightParameters(5000, 35000, 1000, 500)
    boundaries = BoundaryConditions(5000, 40000)
    flight_control_system(flight, boundaries)
main()