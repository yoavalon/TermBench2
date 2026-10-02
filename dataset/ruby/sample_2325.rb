class FlightTrajectory
  def initialize(initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
    @altitude = initial_altitude
    @target = target_altitude
    @climb_rate = rate_of_climb
    @descent_rate = rate_of_descent
  end

  def adjust_altitude
    if @altitude < @target
      @altitude += @climb_rate
    elsif @altitude > @target
      @altitude -= @descent_rate
    end
    @altitude
  end

  def stabilize_altitude
    while (@altitude - @target).abs > 0.1
      adjust_altitude
    end
  end
end

class CruiseAltitudePlanner
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan
    loop do
      @trajectory.stabilize_altitude
      puts "Current Altitude: #{@trajectory.altitude.round(2)}"
    end
  end
end

def main
  initial = 5000.0
  target = 35000.0
  climb = 100.0
  descent = 50.0
  trajectory = FlightTrajectory.new(initial, target, climb, descent)
  planner = CruiseAltitudePlanner.new(trajectory)
  planner.plan
end

main