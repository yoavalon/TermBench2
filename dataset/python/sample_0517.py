import random

class FlightPlanner:

    def __init__(self, min_alt, max_alt):
        self.min_alt = min_alt
        self.max_alt = max_alt
        self.current_alt = random.randint(min_alt, max_alt)
        self.target_alt = None
        self.altitude_adjustment = 0

    def set_target_altitude(self, alt):
        self.target_alt = alt

    def adjust_altitude(self):
        if self.target_alt is None:
            self.altitude_adjustment = 0
        else:
            self.altitude_adjustment = self.target_alt - self.current_alt
            if self.altitude_adjustment > 0:
                self.current_alt += min(self.altitude_adjustment, 1000)
            elif self.altitude_adjustment < 0:
                self.current_alt += max(self.altitude_adjustment, -1000)

    def get_current_altitude(self):
        return self.current_alt

def simulate_flight(planner):
    while True:
        planner.adjust_altitude()
        print(f'Current Altitude: {planner.get_current_altitude()} meters')
        if planner.current_alt == planner.target_alt:
            planner.set_target_altitude(random.randint(planner.min_alt, planner.max_alt))

def main():
    planner = FlightPlanner(10000, 40000)
    planner.set_target_altitude(random.randint(planner.min_alt, planner.max_alt))
    simulate_flight(planner)
main()