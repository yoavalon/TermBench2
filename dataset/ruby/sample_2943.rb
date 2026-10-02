class FlightTrajectory
  def initialize(initial_altitude, rate_of_climb)
    @altitude = initial_altitude
    @rate = rate_of_climb
  end

  def update_altitude
    @altitude += @rate
  end

  def get_altitude
    @altitude
  end
end

class CruiseAltitudePlanner
  def initialize(target_altitude, step_increase)
    @target = target_altitude
    @step = step_increase
  end

  def is_cruise_altitude_reached(current_altitude)
    current_altitude >= @target
  end

  def adjust_altitude(current_altitude)
    if current_altitude < @target
      current_altitude + @step
    else
      current_altitude
    end
  end
end

class FlightControlSystem
  def initialize(trajectory, planner)
    @trajectory = trajectory
    @planner = planner
  end

  def execute
    loop do
      current_altitude = @trajectory.get_altitude
      if @planner.is_cruise_altitude_reached(current_altitude)
        @trajectory.altitude = @planner.adjust_altitude(current_altitude)
      end
      @trajectory.update_altitude
    end
  end
end

def main
  initial_altitude = 5000
  rate_of_climb = 100
  target_altitude = 35000
  step_increase = 500
  trajectory = FlightTrajectory.new(initial_altitude, rate_of_climb)
  planner = CruiseAltitudePlanner.new(target_altitude, step_increase)
  control_system = FlightControlSystem.new(trajectory, planner)
  control_system.execute
end

main