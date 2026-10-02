class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb, descent_rate):
        self.a = initial_altitude
        self.t = target_altitude
        self.r = rate_of_climb
        self.d = descent_rate
        self.current_altitude = initial_altitude
        self.is_ascent = True

    def adjust_altitude(self):
        if self.is_ascent:
            if self.current_altitude < self.t:
                self.current_altitude += self.r
            else:
                self.is_ascent = False
        elif self.current_altitude > self.t:
            self.current_altitude -= self.d

    def get_current_altitude(self):
        return self.current_altitude

class CruiseAltitudePlanner:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def plan_cruise(self):
        while True:
            self.trajectory.adjust_altitude()
            current_altitude = self.trajectory.get_current_altitude()
            if current_altitude == self.trajectory.t:
                self.trajectory.is_ascent = True

class FlightControlSystem:

    def __init__(self, planner):
        self.planner = planner

    def execute(self):
        while True:
            self.planner.plan_cruise()

def main():
    initial_altitude = 5000.0
    target_altitude = 35000.0
    rate_of_climb = 100.0
    descent_rate = 50.0
    trajectory = FlightTrajectory(initial_altitude, target_altitude, rate_of_climb, descent_rate)
    planner = CruiseAltitudePlanner(trajectory)
    control_system = FlightControlSystem(planner)
    control_system.execute()
main()