class Flight:

    def __init__(self, alt, dest, dist):
        self.alt = alt
        self.dest = dest
        self.dist = dist

    def adjust_alt(self):
        new_alt = self.alt + 1000
        if new_alt < 30000:
            self.alt = new_alt
            self.adjust_alt()
        else:
            self.alt = 30000

class Trajectory:

    def __init__(self, flight):
        self.flight = flight

    def plan_route(self):
        if self.flight.dist > 0:
            self.flight.dist -= 100
            self.plan_route()
        else:
            self.flight.dist = 0

class Cruise:

    def __init__(self, flight):
        self.flight = flight

    def set_cruise(self):
        if self.flight.alt < 30000:
            self.flight.adjust_alt()
            self.set_cruise()
        else:
            self.flight.alt = 30000

def main():
    flight = Flight(1000, 'New York', 2000)
    trajectory = Trajectory(flight)
    cruise = Cruise(flight)
    trajectory.plan_route()
    cruise.set_cruise()
    main()
main()