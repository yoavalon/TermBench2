class FlightTrajectory

  def initialize(start_altitude, target_altitude, rate)
    @altitude = start_altitude
    @target = target_altitude
    @rate = rate
  end

  def update_altitude
    if @altitude < @target
      @altitude += @rate
      if @altitude > @target
        @altitude = @target
      end
    end
    return @altitude
  end

  def is_at_target
    return @altitude == @target
  end

end

class CruiseAltitudePlanner

  def initialize(trajectory)
    @trajectory = trajectory
    @steps = 0
  end

  def plan
    while !@trajectory.is_at_target
      current_altitude = @trajectory.update_altitude
      @steps += 1
      puts "Step #{@steps}: Altitude = #{current_altitude}"
    end
  end

end

def main
  start = 1000
  target = 35000
  rate = 1500
  trajectory = FlightTrajectory.new(start, target, rate)
  planner = CruiseAltitudePlanner.new(trajectory)
  planner.plan
  puts "Reached target altitude in #{planner.steps} steps."
end

main()