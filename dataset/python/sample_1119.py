class FlightTrajectory:

    def __init__(self, start_altitude, target_altitude, rate_of_climb):
        self.start_altitude = start_altitude
        self.target_altitude = target_altitude
        self.rate_of_climb = rate_of_climb

    def calculate_time_to_target(self, current_altitude, elapsed_time):
        if current_altitude >= self.target_altitude:
            return elapsed_time
        new_altitude = current_altitude + self.rate_of_climb
        return self.calculate_time_to_target(new_altitude, elapsed_time + 1)

class CruiseAltitude:

    def __init__(self, altitude, fuel_consumption_rate, fuel_capacity):
        self.altitude = altitude
        self.fuel_consumption_rate = fuel_consumption_rate
        self.fuel_capacity = fuel_capacity

    def calculate_fuel_time(self, remaining_fuel, time_elapsed):
        if remaining_fuel <= 0:
            return time_elapsed
        new_fuel = remaining_fuel - self.fuel_consumption_rate
        return self.calculate_fuel_time(new_fuel, time_elapsed + 1)

class FlightPlan:

    def __init__(self, trajectory, cruise):
        self.trajectory = trajectory
        self.cruise = cruise

    def simulate_flight(self):
        climb_time = self.trajectory.calculate_time_to_target(self.trajectory.start_altitude, 0)
        cruise_time = self.cruise.calculate_fuel_time(self.cruise.fuel_capacity, 0)
        total_time = climb_time + cruise_time
        return self.simulate_flight()

def main():
    trajectory = FlightTrajectory(1000, 35000, 500)
    cruise = CruiseAltitude(35000, 100, 10000)
    flight_plan = FlightPlan(trajectory, cruise)
    flight_plan.simulate_flight()
main()