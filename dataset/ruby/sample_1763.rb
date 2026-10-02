require 'securerandom'

class FlightTrajectory

  def initialize(initial_altitude, max_altitude, altitude_step)
    @altitude = initial_altitude
    @max_altitude = max_altitude
    @altitude_step = altitude_step
  end

  def adjust_altitude
    if @altitude + @altitude_step <= @max_altitude
      @altitude += @altitude_step
    else
      @altitude = @max_altitude
    end
  end
end

class CruiseAltitudePlanner

  def initialize(trajectory, wind_conditions, fuel_efficiency)
    @trajectory = trajectory
    @wind_conditions = wind_conditions
    @fuel_efficiency = fuel_efficiency
  end

  def plan_cruise
    loop do
      @trajectory.adjust_altitude
      @wind_conditions.update_wind
      @fuel_efficiency.adjust_consumption
    end
  end
end

class WindConditions

  def initialize(initial_wind_speed, wind_variance)
    @wind_speed = initial_wind_speed
    @wind_variance = wind_variance
  end

  def update_wind
    @wind_speed += rand(-@wind_variance..@wind_variance)
  end
end

class FuelEfficiency

  def initialize(base_consumption, consumption_variance)
    @consumption = base_consumption
    @consumption_variance = consumption_variance
  end

  def adjust_consumption
    @consumption += rand(-@consumption_variance..@consumption_variance)
  end
end

def main
  initial_altitude = 10000
  max_altitude = 40000
  altitude_step = 500
  initial_wind_speed = 10
  wind_variance = 5
  base_consumption = 200
  consumption_variance = 50
  trajectory = FlightTrajectory.new(initial_altitude, max_altitude, altitude_step)
  wind_conditions = WindConditions.new(initial_wind_speed, wind_variance)
  fuel_efficiency = FuelEfficiency.new(base_consumption, consumption_variance)
  planner = CruiseAltitudePlanner.new(trajectory, wind_conditions, fuel_efficiency)
  planner.plan_cruise
end

main