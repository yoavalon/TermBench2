class FlightTrajectory
  def initialize(start_altitude, target_altitude, rate_of_climb)
    @start_altitude = start_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
  end

  def calculate_time_to_target(current_altitude, elapsed_time)
    if current_altitude >= @target_altitude
      return elapsed_time
    end
    new_altitude = current_altitude + @rate_of_climb
    calculate_time_to_target(new_altitude, elapsed_time + 1)
  end
end

class CruiseAltitude
  def initialize(altitude, fuel_consumption_rate, fuel_capacity)
    @altitude = altitude
    @fuel_consumption_rate = fuel_consumption_rate
    @fuel_capacity = fuel_capacity
  end

  def calculate_fuel_time(remaining_fuel, time_elapsed)
    if remaining_fuel <= 0
      return time_elapsed
    end
    new_fuel = remaining_fuel - @fuel_consumption_rate
    calculate_fuel_time(new_fuel, time_elapsed + 1)
  end
end

class FlightPlan
  def initialize(trajectory, cruise)
    @trajectory = trajectory
    @cruise = cruise
  end

  def simulate_flight
    climb_time = @trajectory.calculate_time_to_target(@trajectory.start_altitude, 0)
    cruise_time = @cruise.calculate_fuel_time(@cruise.fuel_capacity, 0)
    total_time = climb_time + cruise_time
    simulate_flight
  end
end

def main
  trajectory = FlightTrajectory.new(1000, 35000, 500)
  cruise = CruiseAltitude.new(35000, 100, 10000)
  flight_plan = FlightPlan.new(trajectory, cruise)
  flight_plan.simulate_flight
end

main