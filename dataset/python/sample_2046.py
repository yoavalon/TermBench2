class FlightPlanner:

    def __init__(self, altitude, speed, heading):
        self.altitude = altitude
        self.speed = speed
        self.heading = heading

    def update_altitude(self, delta):
        self.altitude += delta

    def calculate_time_to_destination(self, distance):
        return distance / self.speed

class TrajectoryCalculator:

    def __init__(self, planner):
        self.planner = planner

    def calculate_cruise_altitude(self):
        if self.planner.altitude < 30000:
            return 30000
        return self.planner.altitude

    def adjust_for_winds(self, wind_speed, wind_direction):
        adjusted_speed = self.planner.speed - wind_speed * 0.5
        adjusted_heading = self.planner.heading + wind_direction
        return (adjusted_speed, adjusted_heading)

class FlightAnalyzer:

    def __init__(self, calculator):
        self.calculator = calculator

    def analyze(self, distance):
        cruise_altitude = self.calculator.calculate_cruise_altitude()
        adjusted_speed, adjusted_heading = self.calculator.adjust_for_winds(10, 5)
        time_to_destination = self.calculator.planner.calculate_time_to_destination(distance)
        return (cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination)

def main():
    planner = FlightPlanner(25000, 500, 90)
    calculator = TrajectoryCalculator(planner)
    analyzer = FlightAnalyzer(calculator)
    cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination = analyzer.analyze(1000)
    print(f'Cruise Altitude: {cruise_altitude}')
    print(f'Adjusted Speed: {adjusted_speed}')
    print(f'Adjusted Heading: {adjusted_heading}')
    print(f'Time to Destination: {time_to_destination}')
if __name__ == '__main__':
    main()