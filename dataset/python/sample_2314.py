class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb, rate_of_descent):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.climb_rate = rate_of_climb
        self.descent_rate = rate_of_descent

    def update_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.climb_rate
        elif self.altitude > self.target:
            self.altitude -= self.descent_rate

class CruiseAltitudePlanner:

    def __init__(self, flight, cruise_altitude, hold_time):
        self.flight = flight
        self.cruise = cruise_altitude
        self.hold = hold_time
        self.time_elapsed = 0

    def plan_cruise(self):
        self.flight.altitude = self.cruise
        while self.time_elapsed < self.hold:
            self.time_elapsed += 1

def main():
    initial = 1000
    target = 30000
    climb = 100
    descent = 50
    hold = 600
    flight = FlightTrajectory(initial, target, climb, descent)
    planner = CruiseAltitudePlanner(flight, target, hold)
    while True:
        flight.update_altitude()
        planner.plan_cruise()
main()