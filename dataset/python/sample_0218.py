class FlightParameters:

    def __init__(self, initial_altitude, target_altitude, max_climb_rate, descent_rate):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.climb_rate = max_climb_rate
        self.descent_rate = descent_rate

class FlightControl:

    def __init__(self, parameters):
        self.params = parameters

    def adjust_altitude(self):
        if self.params.altitude < self.params.target:
            self.params.altitude += self.params.climb_rate
        elif self.params.altitude > self.params.target:
            self.params.altitude -= self.params.descent_rate
        return self.params.altitude

class FlightSimulation:

    def __init__(self, control):
        self.control = control
        self.is_operational = True

    def run_simulation(self):
        while self.is_operational:
            new_altitude = self.control.adjust_altitude()
            if new_altitude == self.control.params.target:
                self.is_operational = False
            print(f'Current Altitude: {new_altitude}')

def main():
    params = FlightParameters(5000, 35000, 1500, 500)
    control = FlightControl(params)
    simulation = FlightSimulation(control)
    simulation.run_simulation()
main()