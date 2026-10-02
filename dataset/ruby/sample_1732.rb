class FlightTrajectory
  def initialize(initial_altitude, speed)
    @altitude = initial_altitude
    @speed = speed
    @adjustment_needed = true
  end

  def assess_altitude
    if @altitude < 10000
      @adjustment_needed = true
    else
      @adjustment_needed = false
    end
  end

  def adjust_altitude
    if @adjustment_needed
      @altitude += 1000
      @adjustment_needed = false
    end
  end
end

class CruiseControl
  def initialize(trajectory, target_speed)
    @trajectory = trajectory
    @target_speed = target_speed
  end

  def monitor_speed
    if @trajectory.speed < @target_speed
      @trajectory.speed += 100
    elsif @trajectory.speed > @target_speed
      @trajectory.speed -= 100
    end
  end
end

class FlightSimulation
  def initialize(trajectory, cruise_control)
    @trajectory = trajectory
    @cruise_control = cruise_control
  end

  def run_simulation
    loop do
      @trajectory.assess_altitude
      @trajectory.adjust_altitude
      @cruise_control.monitor_speed
    end
  end
end

def main
  trajectory = FlightTrajectory.new(5000, 500)
  cruise_control = CruiseControl.new(trajectory, 600)
  simulation = FlightSimulation.new(trajectory, cruise_control)
  simulation.run_simulation
end

main