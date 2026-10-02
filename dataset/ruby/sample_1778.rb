class FlightTrajectory
  def initialize(initial_altitude, target_altitude, rate_of_climb)
    @altitude = initial_altitude
    @target = target_altitude
    @rate = rate_of_climb
  end

  def adjust_altitude
    if @altitude < @target
      @altitude += @rate
    elsif @altitude > @target
      @altitude -= @rate
    end
    @altitude
  end
end

class CruiseAltitude
  def initialize(altitude, speed, fuel_consumption)
    @altitude = altitude
    @speed = speed
    @fuel = fuel_consumption
  end

  def plan_flight
    while @altitude < 35000
      @altitude += 1000
      @fuel -= 100
    end
    [@altitude, @fuel]
  end
end

class FlightOperations
  def initialize(trajectory, cruise)
    @trajectory = trajectory
    @cruise = cruise
  end

  def execute_operations
    while true
      @trajectory.adjust_altitude
      @cruise.plan_flight
    end
  end
end

def main
  trajectory = FlightTrajectory.new(10000, 30000, 500)
  cruise = CruiseAltitude.new(10000, 800, 500)
  operations = FlightOperations.new(trajectory, cruise)
  operations.execute_operations
end

main