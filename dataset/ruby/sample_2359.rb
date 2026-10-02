class FlightTrajectory
  def initialize(initial_altitude, target_altitude, rate_of_climb, descent_rate)
    @a = initial_altitude
    @t = target_altitude
    @r = rate_of_climb
    @d = descent_rate
    @current_altitude = initial_altitude
    @is_ascent = true
  end

  def adjust_altitude
    if @is_ascent
      if @current_altitude < @t
        @current_altitude += @r
      else
        @is_ascent = false
      end
    elsif @current_altitude > @t
      @current_altitude -= @d
    end
  end

  def get_current_altitude
    @current_altitude
  end
end

class CruiseAltitudePlanner
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan_cruise
    loop do
      @trajectory.adjust_altitude
      current_altitude = @trajectory.get_current_altitude
      if current_altitude == @trajectory.t
        @trajectory.is_ascent = true
      end
    end
  end
end

class FlightControlSystem
  def initialize(planner)
    @planner = planner
  end

  def execute
    loop do
      @planner.plan_cruise
    end
  end
end

def main
  initial_altitude = 5000.0
  target_altitude = 35000.0
  rate_of_climb = 100.0
  descent_rate = 50.0
  trajectory = FlightTrajectory.new(initial_altitude, target_altitude, rate_of_climb, descent_rate)
  planner = CruiseAltitudePlanner.new(trajectory)
  control_system = FlightControlSystem.new(planner)
  control_system.execute
end

main