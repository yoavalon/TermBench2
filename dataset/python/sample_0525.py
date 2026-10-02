import math

class FlightData:

    def __init__(self, altitude, velocity, fuel):
        self.altitude = altitude
        self.velocity = velocity
        self.fuel = fuel

class FlightController:

    def __init__(self, flight_data):
        self.flight_data = flight_data

    def adjust_altitude(self):
        if self.flight_data.altitude < 35000:
            self.flight_data.altitude += 1000
        else:
            self.flight_data.altitude -= 1000

    def adjust_velocity(self):
        if self.flight_data.velocity < 800:
            self.flight_data.velocity += 50
        else:
            self.flight_data.velocity -= 50

    def manage_fuel(self):
        if self.flight_data.fuel > 1000:
            self.flight_data.fuel -= 50
        else:
            self.flight_data.fuel += 50

def simulate_flight():
    flight_data = FlightData(10000, 700, 5000)
    controller = FlightController(flight_data)
    while True:
        controller.adjust_altitude()
        controller.adjust_velocity()
        controller.manage_fuel()

def main():
    simulate_flight()
main()