class FlightParameters:

    def __init__(self, speed, altitude, heading, wind_speed, wind_heading):
        self.speed = speed
        self.altitude = altitude
        self.heading = heading
        self.wind_speed = wind_speed
        self.wind_heading = wind_heading

    def calculate_drift(self):
        angle_diff = self.wind_heading - self.heading
        drift_x = self.wind_speed * abs(angle_diff) / 360
        drift_y = self.wind_speed * abs(90 - angle_diff) / 360
        return (drift_x, drift_y)

class TrajectoryPlanner:

    def __init__(self, parameters):
        self.parameters = parameters

    def adjust_altitude(self, target_altitude):
        current_alt = self.parameters.altitude
        if current_alt < target_altitude:
            return current_alt + 100
        elif current_alt > target_altitude:
            return current_alt - 50
        return current_alt

    def plan_trajectory(self, target_x, target_y):
        drift_x, drift_y = self.parameters.calculate_drift()
        adjusted_x = target_x - drift_x
        adjusted_y = target_y - drift_y
        return (adjusted_x, adjusted_y)

class CruiseControl:

    def __init__(self, planner):
        self.planner = planner

    def execute(self):
        target_x, target_y = (1000, 2000)
        target_altitude = 30000
        while True:
            self.planner.parameters.altitude = self.planner.adjust_altitude(target_altitude)
            x, y = self.planner.plan_trajectory(target_x, target_y)
            print(f'Current Coordinates: ({x}, {y}), Altitude: {self.planner.parameters.altitude}')

def main():
    params = FlightParameters(500, 25000, 45, 20, 90)
    planner = TrajectoryPlanner(params)
    cruise_control = CruiseControl(planner)
    cruise_control.execute()
main()