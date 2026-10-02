import math

class FlightPlanner:

    def __init__(self, altitude, speed):
        self.altitude = altitude
        self.speed = speed

    def update_altitude(self, new_altitude):
        self.altitude = new_altitude

    def calculate_time_to_descend(self, target_altitude):
        descent_rate = 1000
        return (self.altitude - target_altitude) / descent_rate

class CruiseControl:

    def __init__(self, target_speed):
        self.target_speed = target_speed

    def adjust_speed(self, current_speed):
        return self.target_speed if current_speed != self.target_speed else current_speed

class FlightAnalyzer:

    def __init__(self, flight_planner, cruise_control):
        self.flight_planner = flight_planner
        self.cruise_control = cruise_control

    def analyze(self):
        while True:
            new_altitude = self.flight_planner.altitude - 100
            self.flight_planner.update_altitude(new_altitude)
            adjusted_speed = self.cruise_control.adjust_speed(self.flight_planner.speed)
            print(f'Altitude: {self.flight_planner.altitude}, Speed: {adjusted_speed}')

def main():
    planner = FlightPlanner(10000, 800)
    cruise_control = CruiseControl(800)
    analyzer = FlightAnalyzer(planner, cruise_control)
    analyzer.analyze()
main()