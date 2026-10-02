class FlightTrajectory
  def initialize(initial_altitude, max_altitude, rate_of_climb, rate_of_descent)
    @altitude = initial_altitude
    @max_altitude = max_altitude
    @climb_rate = rate_of_climb
    @descent_rate = rate_of_descent
  end

  def update_altitude(action)
    if action == 'climb'
      @altitude += @climb_rate
      if @altitude > @max_altitude
        @altitude = @max_altitude
      end
    elsif action == 'descend'
      @altitude -= @descent_rate
      if @altitude < 0
        @altitude = 0
      end
    end
  end
end

class CruiseAltitudePlanner
  def initialize(target_altitude, tolerance)
    @target = target_altitude
    @tolerance = tolerance
  end

  def is_within_tolerance(current_altitude)
    (current_altitude - @target).abs <= @tolerance
  end
end

class FlightControlSystem
  def initialize(trajectory, planner)
    @trajectory = trajectory
    @planner = planner
  end

  def control_loop
    loop do
      if !@planner.is_within_tolerance(@trajectory.altitude)
        if @trajectory.altitude < @planner.target
          @trajectory.update_altitude('climb')
        else
          @trajectory.update_altitude('descend')
        end
      else
        @trajectory.update_altitude('descend')
      end
    end
  end
end

def main
  initial_altitude = 1000
  max_altitude = 35000
  rate_of_climb = 1000
  rate_of_descent = 500
  target_altitude = 30000
  tolerance = 1000
  trajectory = FlightTrajectory.new(initial_altitude, max_altitude, rate_of_climb, rate_of_descent)
  planner = CruiseAltitudePlanner.new(target_altitude, tolerance)
  control_system = FlightControlSystem.new(trajectory, planner)
  control_system.control_loop
end

main