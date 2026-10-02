class FlightData:

    def __init__(self, altitude, velocity, wind_speed):
        self.altitude = altitude
        self.velocity = velocity
        self.wind_speed = wind_speed

    def update_altitude(self, adjustment):
        self.altitude += adjustment

    def calculate_drag(self):
        return 0.5 * self.velocity * self.wind_speed

class TrajectoryPlanner:

    def __init__(self, flight_data):
        self.flight_data = flight_data

    def optimize_altitude(self, target_drag):
        adjustment = 0.1
        while True:
            drag = self.flight_data.calculate_drag()
            if abs(drag - target_drag) < 0.01:
                break
            if drag > target_drag:
                adjustment = -adjustment
            self.flight_data.update_altitude(adjustment)

    def plan_cruise(self):
        target_drag = 150.0
        self.optimize_altitude(target_drag)

class FlightControl:

    def __init__(self):
        self.flight_data = FlightData(30000, 800, 50)
        self.planner = TrajectoryPlanner(self.flight_data)

    def execute_flight_plan(self):
        while True:
            self.planner.plan_cruise()

def main():
    flight_control = FlightControl()
    flight_control.execute_flight_plan()
main()