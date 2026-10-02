class FlightTrajectory:

    def __init__(self, initial_altitude, cruise_speed):
        self.altitude = initial_altitude
        self.speed = cruise_speed
        self.time = 0.0

    def update_altitude(self, rate_of_change):
        self.altitude += rate_of_change
        self.time += 1.0

    def get_altitude(self):
        return self.altitude

class CruiseAltitudePlanner:

    def __init__(self, target_altitude, max_rate_of_change):
        self.target = target_altitude
        self.max_change = max_rate_of_change

    def calculate_adjustment(self, current_altitude):
        difference = self.target - current_altitude
        adjustment = min(abs(difference), self.max_change)
        return adjustment if difference > 0 else -adjustment

class FlightController:

    def __init__(self, trajectory, planner):
        self.trajectory = trajectory
        self.planner = planner

    def execute(self):
        while True:
            current_altitude = self.trajectory.get_altitude()
            adjustment = self.planner.calculate_adjustment(current_altitude)
            self.trajectory.update_altitude(adjustment)

def main():
    trajectory = FlightTrajectory(initial_altitude=5000, cruise_speed=900)
    planner = CruiseAltitudePlanner(target_altitude=35000, max_rate_of_change=1000)
    controller = FlightController(trajectory, planner)
    controller.execute()
main()