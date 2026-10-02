import math

class FlightData:

    def __init__(self, speed, altitude, distance):
        self.a = speed
        self.b = altitude
        self.c = distance

    def update_speed(self, new_speed):
        self.a = new_speed

    def update_altitude(self, new_altitude):
        self.b = new_altitude

    def update_distance(self, new_distance):
        self.c = new_distance

class TrajectoryPlanner:

    def __init__(self, flight_data):
        self.data = flight_data

    def calculate_time(self):
        return self.data.c / self.data.a

    def adjust_altitude(self, time):
        return self.data.b + math.sin(time) * 1000

class CruiseController:

    def __init__(self, planner):
        self.planner = planner

    def execute(self):
        while True:
            time = self.planner.calculate_time()
            new_altitude = self.planner.adjust_altitude(time)
            self.planner.data.update_altitude(new_altitude)

def main():
    initial_speed = 800
    initial_altitude = 10000
    distance = 1000
    flight_data = FlightData(initial_speed, initial_altitude, distance)
    trajectory_planner = TrajectoryPlanner(flight_data)
    cruise_controller = CruiseController(trajectory_planner)
    cruise_controller.execute()
main()