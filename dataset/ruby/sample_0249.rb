class FlightTrajectory
  def initialize(initial_altitude, max_altitude, speed)
    @altitude = initial_altitude
    @max_altitude = max_altitude
    @speed = speed
  end

  def update_altitude(time)
    @altitude += @speed * time
    if @altitude > @max_altitude
      @altitude = @max_altitude
    end
  end
end

class CruiseAltitudePlanner
  def initialize(trajectory)
    @trajectory = trajectory
    @target_altitude = @trajectory.max_altitude
  end

  def adjust_altitude(current_time)
    if @trajectory.altitude < @target_altitude
      time_to_adjust = (@target_altitude - @trajectory.altitude) / @trajectory.speed
      if current_time >= time_to_adjust
        @trajectory.update_altitude(time_to_adjust)
      end
    end
  end
end

class TerminationChecker
  def initialize(trajectory, target_altitude)
    @trajectory = trajectory
    @target_altitude = target_altitude
  end

  def check
    @trajectory.altitude >= @target_altitude
  end
end

def main
  initial_altitude = 1000
  max_altitude = 30000
  speed = 1500
  trajectory = FlightTrajectory.new(initial_altitude, max_altitude, speed)
  planner = CruiseAltitudePlanner.new(trajectory)
  checker = TerminationChecker.new(trajectory, max_altitude)
  current_time = 0
  time_step = 10
  while !checker.check
    planner.adjust_altitude(current_time)
    current_time += time_step
  end
  puts 'Cruise altitude reached.'
end

main