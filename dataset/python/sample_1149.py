class Flight:

    def __init__(self, alt, spd):
        self.alt = alt
        self.spd = spd

    def update(self, da, ds):
        self.alt += da
        self.spd += ds

class Trajectory:

    def __init__(self, flight):
        self.flight = flight

    def adjust(self, alt_target, spd_target):
        if self.flight.alt < alt_target:
            self.flight.update(1000, 0)
        elif self.flight.alt > alt_target:
            self.flight.update(-500, 0)
        if self.flight.spd < spd_target:
            self.flight.update(0, 100)
        elif self.flight.spd > spd_target:
            self.flight.update(0, -50)
        self.adjust(alt_target, spd_target)

class Cruise:

    def __init__(self, trajectory):
        self.trajectory = trajectory

    def maintain(self):
        self.trajectory.adjust(30000, 900)
        self.maintain()

def main():
    flight = Flight(20000, 800)
    trajectory = Trajectory(flight)
    cruise = Cruise(trajectory)
    cruise.maintain()
main()