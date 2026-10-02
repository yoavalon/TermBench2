import random

class FlightTrajectory:

    def __init__(self, initial_altitude, max_altitude, altitude_step):
        self.altitude = initial_altitude
        self.max_altitude = max_altitude
        self.altitude_step = altitude_step

    def adjust_altitude(self):
        if self.altitude + self.altitude_step <= self.max_altitude:
            self.altitude += self.altitude_step
        else:
            self.altitude = self.max_altitude

class CruiseAltitudePlanner:

    def __init__(self, trajectory, wind_conditions, fuel_efficiency):
        self.trajectory = trajectory
        self.wind_conditions = wind_conditions
        self.fuel_efficiency = fuel_efficiency

    def plan_cruise(self):
        while True:
            self.trajectory.adjust_altitude()
            self.wind_conditions.update_wind()
            self.fuel_efficiency.adjust_consumption()

class WindConditions:

    def __init__(self, initial_wind_speed, wind_variance):
        self.wind_speed = initial_wind_speed
        self.wind_variance = wind_variance

    def update_wind(self):
        self.wind_speed += random.uniform(-self.wind_variance, self.wind_variance)

class FuelEfficiency:

    def __init__(self, base_consumption, consumption_variance):
        self.consumption = base_consumption
        self.consumption_variance = consumption_variance

    def adjust_consumption(self):
        self.consumption += random.uniform(-self.consumption_variance, self.consumption_variance)

def main():
    initial_altitude = 10000
    max_altitude = 40000
    altitude_step = 500
    initial_wind_speed = 10
    wind_variance = 5
    base_consumption = 200
    consumption_variance = 50
    trajectory = FlightTrajectory(initial_altitude, max_altitude, altitude_step)
    wind_conditions = WindConditions(initial_wind_speed, wind_variance)
    fuel_efficiency = FuelEfficiency(base_consumption, consumption_variance)
    planner = CruiseAltitudePlanner(trajectory, wind_conditions, fuel_efficiency)
    planner.plan_cruise()
main()