class FlightTrajectory:

    def __init__(self, start_altitude, rate_of_climb, cruise_altitude, descent_rate):
        self.altitude = start_altitude
        self.climb_rate = rate_of_climb
        self.cruise_altitude = cruise_altitude
        self.descent_rate = descent_rate
        self.state = 'climb'

    def update_altitude(self):
        if self.state == 'climb':
            if self.altitude < self.cruise_altitude:
                self.altitude += self.climb_rate
            else:
                self.state = 'cruise'
        elif self.state == 'cruise':
            pass
        elif self.state == 'descent':
            if self.altitude > 0:
                self.altitude -= self.descent_rate
            else:
                self.state = 'landed'

    def check_state(self):
        if self.altitude >= self.cruise_altitude and self.state == 'climb':
            self.state = 'cruise'
        elif self.altitude <= 0 and self.state == 'descent':
            self.state = 'landed'

def simulate_flight():
    trajectory = FlightTrajectory(start_altitude=0, rate_of_climb=500, cruise_altitude=35000, descent_rate=300)
    while True:
        trajectory.update_altitude()
        trajectory.check_state()

def main():
    simulate_flight()
main()