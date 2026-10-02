class FlightTrajectory:

    def __init__(self, speed, altitude, distance):
        self.speed = speed
        self.altitude = altitude
        self.distance = distance

    def calculate_time(self):
        return self.distance / self.speed

    def adjust_altitude(self, new_altitude):
        self.altitude = new_altitude

class CruiseAltitudePlanner:

    def __init__(self, max_altitude, min_altitude, step):
        self.max_altitude = max_altitude
        self.min_altitude = min_altitude
        self.step = step

    def suggest_altitudes(self):
        altitudes = []
        current = self.min_altitude
        while current <= self.max_altitude:
            altitudes.append(current)
            current += self.step
        return altitudes

def optimize_flight_plan(trajectory, planner):
    altitudes = planner.suggest_altitudes()
    best_time = float('inf')
    best_altitude = None
    for altitude in altitudes:
        trajectory.adjust_altitude(altitude)
        time = trajectory.calculate_time()
        if time < best_time:
            best_time = time
            best_altitude = altitude
    trajectory.adjust_altitude(best_altitude)
    return (trajectory.altitude, trajectory.calculate_time())

def main():
    trajectory = FlightTrajectory(speed=800, altitude=30000, distance=1000)
    planner = CruiseAltitudePlanner(max_altitude=40000, min_altitude=20000, step=5000)
    best_altitude, best_time = optimize_flight_plan(trajectory, planner)
    print('Best Altitude:', best_altitude, 'meters')
    print('Time to Destination:', best_time, 'hours')
main()