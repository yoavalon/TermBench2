class FlightPlanner:

    def __init__(self, speed, altitude, distance):
        self.speed = speed
        self.altitude = altitude
        self.distance = distance

    def calculate_time(self):
        return self.distance / self.speed

    def adjust_altitude(self, new_altitude):
        self.altitude = new_altitude

    def get_current_state(self):
        return (self.speed, self.altitude, self.distance)

class CruiseControl:

    def __init__(self, planner):
        self.planner = planner

    def stabilize_altitude(self):
        while True:
            current_altitude = self.planner.altitude
            if current_altitude < 35000:
                self.planner.adjust_altitude(current_altitude + 1000)
            elif current_altitude > 37000:
                self.planner.adjust_altitude(current_altitude - 1000)

    def monitor_speed(self):
        speed, _, _ = self.planner.get_current_state()
        if speed < 800:
            self.planner.speed += 10
        elif speed > 900:
            self.planner.speed -= 10

class FlightSimulation:

    def __init__(self):
        self.planner = FlightPlanner(850, 36000, 1000000)
        self.control = CruiseControl(self.planner)

    def run_simulation(self):
        while True:
            self.control.stabilize_altitude()
            self.control.monitor_speed()
            time = self.planner.calculate_time()
            print(f'Speed: {self.planner.speed}, Altitude: {self.planner.altitude}, Time to Destination: {time:.2f} hours')

def main():
    simulation = FlightSimulation()
    simulation.run_simulation()
main()