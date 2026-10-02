class FlightTrajectory:

    def __init__(self, initial_altitude, cruising_speed, wind_speed):
        self.altitude = initial_altitude
        self.speed = cruising_speed
        self.wind = wind_speed
        self.time = 0

    def update_altitude(self, altitude_change):
        self.altitude += altitude_change

    def update_time(self, increment):
        self.time += increment

class CruiseAltitudePlanner:

    def __init__(self, target_altitude, max_altitude_change):
        self.target = target_altitude
        self.max_change = max_altitude_change

    def calculate_adjustment(self, current_altitude):
        return min(max(self.target - current_altitude, -self.max_change), self.max_change)

class FlightController:

    def __init__(self, trajectory, planner):
        self.trajectory = trajectory
        self.planner = planner
        self.interval = 1.0

    def control_loop(self):
        while True:
            adjustment = self.planner.calculate_adjustment(self.trajectory.altitude)
            self.trajectory.update_altitude(adjustment)
            self.trajectory.update_time(self.interval)

def main():
    initial_altitude = 30000
    cruising_speed = 800
    wind_speed = 50
    target_altitude = 35000
    max_altitude_change = 500
    trajectory = FlightTrajectory(initial_altitude, cruising_speed, wind_speed)
    planner = CruiseAltitudePlanner(target_altitude, max_altitude_change)
    controller = FlightController(trajectory, planner)
    controller.control_loop()
main()