require 'matrix'

class FlightTrajectory
  def initialize(initial_altitude, target_altitude, max_altitude, rate_of_climb)
    @altitude = initial_altitude
    @target_altitude = target_altitude
    @max_altitude = max_altitude
    @rate_of_climb = rate_of_climb
    @time = 0
  end

  def update_altitude
    if @altitude < @target_altitude
      @altitude += @rate_of_climb
      if @altitude > @max_altitude
        @altitude = @max_altitude
      end
    end
    @time += 1
  end

  def is_complete
    @altitude >= @target_altitude
  end
end

class CruiseAltitudePlanner
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan_cruise
    while !@trajectory.is_complete
      @trajectory.update_altitude
    end
    [@trajectory.altitude, @trajectory.time]
  end
end

def main
  initial_altitude = 1000
  target_altitude = 35000
  max_altitude = 40000
  rate_of_climb = 1500
  trajectory = FlightTrajectory.new(initial_altitude, target_altitude, max_altitude, rate_of_climb)
  planner = CruiseAltitudePlanner.new(trajectory)
  final_altitude, climb_time = planner.plan_cruise
  puts "Final Altitude: #{final_altitude}, Climb Time: #{climb_time}"
end

main if __FILE__ == $0