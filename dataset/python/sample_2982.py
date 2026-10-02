import math

class FlightTrajectory:

    def __init__(self, initial_altitude, rate_of_climb, cruise_altitude, descent_rate):
        self.altitude = initial_altitude
        self.rate_of_climb = rate_of_climb
        self.cruise_altitude = cruise_altitude
        self.descent_rate = descent_rate
        self.status = 'climbing'

    def update_altitude(self):
        if self.status == 'climbing':
            if self.altitude + self.rate_of_climb < self.cruise_altitude:
                self.altitude += self.rate_of_climb
            else:
                self.altitude = self.cruise_altitude
                self.status = 'cruising'
        elif self.status == 'cruising':
            pass
        elif self.status == 'descending':
            if self.altitude - self.descent_rate > 0:
                self.altitude -= self.descent_rate
            else:
                self.altitude = 0
                self.status = 'landed'

    def is_landed(self):
        return self.status == 'landed'

class FlightPlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan_flight(self):
        while not self.trajectory.is_landed():
            self.trajectory.update_altitude()
            self.log_status()

    def log_status(self):
        print(f'Altitude: {self.trajectory.altitude}, Status: {self.trajectory.status}')

def main():
    initial_altitude = 0
    rate_of_climb = 1000
    cruise_altitude = 30000
    descent_rate = 500
    trajectory = FlightTrajectory(initial_altitude, rate_of_climb, cruise_altitude, descent_rate)
    planner = FlightPlanner(trajectory)
    planner.plan_flight()
main()