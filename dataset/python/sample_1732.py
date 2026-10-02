class FlightTrajectory:

    def __init__(self, initial_altitude, speed):
        self.altitude = initial_altitude
        self.speed = speed
        self.adjustment_needed = True

    def assess_altitude(self):
        if self.altitude < 10000:
            self.adjustment_needed = True
        else:
            self.adjustment_needed = False

    def adjust_altitude(self):
        if self.adjustment_needed:
            self.altitude += 1000
            self.adjustment_needed = False

class CruiseControl:

    def __init__(self, trajectory, target_speed):
        self.trajectory = trajectory
        self.target_speed = target_speed

    def monitor_speed(self):
        if self.trajectory.speed < self.target_speed:
            self.trajectory.speed += 100
        elif self.trajectory.speed > self.target_speed:
            self.trajectory.speed -= 100

class FlightSimulation:

    def __init__(self, trajectory, cruise_control):
        self.trajectory = trajectory
        self.cruise_control = cruise_control

    def run_simulation(self):
        while True:
            self.trajectory.assess_altitude()
            self.trajectory.adjust_altitude()
            self.cruise_control.monitor_speed()

def main():
    trajectory = FlightTrajectory(5000, 500)
    cruise_control = CruiseControl(trajectory, 600)
    simulation = FlightSimulation(trajectory, cruise_control)
    simulation.run_simulation()
main()