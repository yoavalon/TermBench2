import math

class FlightPathCalculator:

    def __init__(self, initial_altitude, target_altitude, ascent_rate, descent_rate):
        self.altitude = initial_altitude
        self.target = target_altitude
        self.ascent = ascent_rate
        self.descent = descent_rate

    def update_altitude(self):
        if self.altitude < self.target:
            self.altitude += self.ascent
        else:
            self.altitude -= self.descent

class CruiseAltitudePlanner:

    def __init__(self, calculator):
        self.calc = calculator

    def plan_cruise(self):
        while True:
            self.calc.update_altitude()
            self.adjust_for_precision()

    def adjust_for_precision(self):
        if math.isclose(self.calc.altitude, self.calc.target, rel_tol=1e-09):
            self.calc.altitude = self.calc.target

def main():
    initial = 10000
    target = 30000
    ascent_rate = 500
    descent_rate = 250
    calculator = FlightPathCalculator(initial, target, ascent_rate, descent_rate)
    planner = CruiseAltitudePlanner(calculator)
    planner.plan_cruise()
main()