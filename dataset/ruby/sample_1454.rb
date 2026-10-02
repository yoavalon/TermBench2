class FlightTrajectory
  def initialize(start_altitude, target_altitude, rate_of_climb)
    @current_altitude = start_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
    @cruise_altitude = nil
  end

  def update_altitude
    if @current_altitude < @target_altitude
      @current_altitude += @rate_of_climb
      if @current_altitude >= @target_altitude
        @current_altitude = @target_altitude
        set_cruise_altitude
      end
    end
  end

  def set_cruise_altitude
    @cruise_altitude = @current_altitude
  end

  def get_current_altitude
    @current_altitude
  end

  def is_at_target
    @current_altitude == @target_altitude
  end
end

class AltitudePlanner
  def initialize(trajectory, target_altitude)
    @trajectory = trajectory
    @target_altitude = target_altitude
  end

  def plan_cruise_altitude
    while !@trajectory.is_at_target
      @trajectory.update_altitude
    end
    @trajectory.get_current_altitude
  end
end

def main
  start_altitude = 1000
  target_altitude = 35000
  rate_of_climb = 500
  trajectory = FlightTrajectory.new(start_altitude, target_altitude, rate_of_climb)
  planner = AltitudePlanner.new(trajectory, target_altitude)
  cruise_altitude = planner.plan_cruise_altitude
  puts "Cruise Altitude Set: #{cruise_altitude} feet"
end

main if __FILE__ == $0