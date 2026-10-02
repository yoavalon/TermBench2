class FlightTrajectory:

    def __init__(self, start_altitude, target_altitude, rate_of_climb):
        self.current_altitude = start_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb
        self.cruise_altitude = None

    def update_altitude(self):
        if self.current_altitude < self.target_altitude:
            self.current_altitude += self.rate_of_climb
            if self.current_altitude >= self.target_altitude:
                self.current_altitude = self.target_altitude
                self.set_cruise_altitude()

    def set_cruise_altitude(self):
        self.cruise_altitude = self.current_altitude

    def get_current_altitude(self):
        return self.current_altitude

    def is_at_target(self):
        return self.current_altitude == self.target_altitude

class AltitudePlanner:

    def __init__(self, trajectory, target_altitude):
        self.trajectory = trajectory
        self.target_altitude = target_altitude

    def plan_cruise_altitude(self):
        while not self.trajectory.is_at_target():
            self.trajectory.update_altitude()
        return self.trajectory.get_current_altitude()

def main():
    start_altitude = 1000
    target_altitude = 35000
    rate_of_climb = 500
    trajectory = FlightTrajectory(start_altitude, target_altitude, rate_of_climb)
    planner = AltitudePlanner(trajectory, target_altitude)
    cruise_altitude = planner.plan_cruise_altitude()
    print(f'Cruise Altitude Set: {cruise_altitude} feet')
if __name__ == '__main__':
    main()