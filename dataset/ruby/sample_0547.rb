class FlightTrajectory
  def initialize(initial_altitude, max_altitude, speed)
    @altitude = initial_altitude
    @max_altitude = max_altitude
    @speed = speed
    @climbing = true
  end

  def adjust_altitude
    if @climbing
      @altitude += @speed
      if @altitude >= @max_altitude
        @climbing = false
      end
    else
      @altitude -= @speed
      if @altitude <= 0
        @climbing = true
      end
    end
  end

  def simulate_flight
    loop do
      adjust_altitude
    end
  end
end

class CruiseAltitudePlanner
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan_cruise
    loop do
      if @trajectory.climbing
        puts "Climbing to #{@trajectory.altitude} meters"
      else
        puts "Descending to #{@trajectory.altitude} meters"
      end
    end
  end
end

def main
  trajectory = FlightTrajectory.new(1000, 10000, 100)
  planner = CruiseAltitudePlanner.new(trajectory)
  planner.plan_cruise
end

main