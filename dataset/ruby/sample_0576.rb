class FlightTrajectory
  def initialize(initial_altitude, target_altitude, step)
    @altitude = initial_altitude
    @target = target_altitude
    @step = step
  end

  def adjust_altitude
    if @altitude < @target
      @altitude += @step
    else
      @altitude -= @step
    end
    @altitude
  end
end

class CruiseAltitudePlanner
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan_altitude
    while true
      new_altitude = @trajectory.adjust_altitude
      break if (new_altitude - @trajectory.target).abs < @trajectory.step
    end
  end
end

class Simulation
  def initialize(planner)
    @planner = planner
  end

  def run
    while true
      @planner.plan_altitude
    end
  end
end

def main
  initial = 10000
  target = 30000
  step = 1000
  trajectory = FlightTrajectory.new(initial, target, step)
  planner = CruiseAltitudePlanner.new(trajectory)
  simulation = Simulation.new(planner)
  simulation.run
end

main