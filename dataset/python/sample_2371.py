class FlightPlan:

    def __init__(self, altitude, speed, heading, duration):
        self.altitude = altitude
        self.speed = speed
        self.heading = heading
        self.duration = duration

    def calculate_distance(self):
        distance = self.speed * self.duration
        return distance

    def adjust_altitude(self, adjustment):
        self.altitude += adjustment

class TrajectoryAnalyzer:

    def __init__(self, plan):
        self.plan = plan

    def analyze_cruise(self):
        distance = self.plan.calculate_distance()
        adjusted_altitude = self.plan.altitude + 0.5
        return (distance, adjusted_altitude)

class FlightController:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def control_cruise(self):
        while True:
            distance, altitude = self.analyzer.analyze_cruise()
            print(f'Distance: {distance:.2f}, Altitude: {altitude:.2f}')

def main():
    altitude = 30000.0
    speed = 500.0
    heading = 270
    duration = 5
    flight_plan = FlightPlan(altitude, speed, heading, duration)
    trajectory_analyzer = TrajectoryAnalyzer(flight_plan)
    flight_controller = FlightController(trajectory_analyzer)
    flight_controller.control_cruise()
main()