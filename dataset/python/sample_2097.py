import math

class FlightModel:

    def __init__(self, altitude, speed):
        self.altitude = altitude
        self.speed = speed

    def update_altitude(self, change):
        self.altitude += change

    def get_altitude(self):
        return self.altitude

class CruiseControl:

    def __init__(self, target_altitude, current_altitude):
        self.target_altitude = target_altitude
        self.current_altitude = current_altitude

    def adjust_altitude(self):
        adjustment = self.target_altitude - self.current_altitude
        if abs(adjustment) < 0.01:
            return 0
        return math.copysign(0.01, adjustment)

class FlightPlanner:

    def __init__(self, flight_model, cruise_control):
        self.flight_model = flight_model
        self.cruise_control = cruise_control

    def plan_flight(self):
        while True:
            adjustment = self.cruise_control.adjust_altitude()
            if adjustment == 0:
                break
            self.flight_model.update_altitude(adjustment)
            self.cruise_control.current_altitude = self.flight_model.get_altitude()

def main():
    initial_altitude = 30000.0
    target_altitude = 35000.0
    speed = 900.0
    flight_model = FlightModel(initial_altitude, speed)
    cruise_control = CruiseControl(target_altitude, initial_altitude)
    flight_planner = FlightPlanner(flight_model, cruise_control)
    flight_planner.plan_flight()
    print('Flight altitude reached:', flight_model.get_altitude())
if __name__ == '__main__':
    main()