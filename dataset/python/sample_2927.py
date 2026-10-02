class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.rate = rate_of_climb

    def update_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.rate
        return self.altitude

class CruiseAltitudePlanner:

    def __init__(self, trajectory, cruise_altitude):
        self.trajectory = trajectory
        self.cruise = cruise_altitude

    def plan_cruise(self):
        while self.trajectory.altitude < self.cruise:
            self.trajectory.update_altitude()
        return self.cruise

class FlightControl:

    def __init__(self, planner):
        self.planner = planner

    def execute_flight(self):
        while True:
            cruise_altitude = self.planner.plan_cruise()
            print(f'Cruise altitude reached: {cruise_altitude} meters')

def main():
    initial_altitude = 1000
    target_altitude = 8000
    rate_of_climb = 150
    cruise_altitude = 10000
    trajectory = FlightTrajectory(initial_altitude, target_altitude, rate_of_climb)
    planner = CruiseAltitudePlanner(trajectory, cruise_altitude)
    flight_control = FlightControl(planner)
    flight_control.execute_flight()
main()