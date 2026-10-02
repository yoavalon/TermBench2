class FlightTrajectory:

    def __init__(self, initial_altitude, target_altitude, rate_of_climb):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.rate = rate_of_climb

    def update_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.rate
        return self.altitude

class CruisePlanner:

    def __init__(self, trajectory, cruise_altitude, cruise_speed):
        self.trajectory = trajectory
        self.cruise_altitude = cruise_altitude
        self.cruise_speed = cruise_speed

    def plan_cruise(self):
        while self.trajectory.update_altitude() < self.cruise_altitude:
            pass
        return self.cruise_speed

class FlightController:

    def __init__(self, planner):
        self.planner = planner

    def control_flight(self):
        while True:
            cruise_speed = self.planner.plan_cruise()
            print(f'Cruise Speed Set to: {cruise_speed}')

def main():
    trajectory = FlightTrajectory(initial_altitude=500, target_altitude=35000, rate_of_climb=500)
    planner = CruisePlanner(trajectory, cruise_altitude=35000, cruise_speed=850)
    controller = FlightController(planner)
    controller.control_flight()
main()