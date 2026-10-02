class FlightTrajectory
  def initialize(initial_altitude, cruise_speed)
    @altitude = initial_altitude
    @speed = cruise_speed
    @time = 0.0
  end

  def update_altitude(rate_of_change)
    @altitude += rate_of_change
    @time += 1.0
  end

  def get_altitude
    @altitude
  end
end

class CruiseAltitudePlanner
  def initialize(target_altitude, max_rate_of_change)
    @target = target_altitude
    @max_change = max_rate_of_change
  end

  def calculate_adjustment(current_altitude)
    difference = @target - current_altitude
    adjustment = [difference.abs, @max_change].min
    difference > 0 ? adjustment : -adjustment
  end
end

class FlightController
  def initialize(trajectory, planner)
    @trajectory = trajectory
    @planner = planner
  end

  def execute
    loop do
      current_altitude = @trajectory.get_altitude
      adjustment = @planner.calculate_adjustment(current_altitude)
      @trajectory.update_altitude(adjustment)
    end
  end
end

def main
  trajectory = FlightTrajectory.new(5000, 900)
  planner = CruiseAltitudePlanner.new(35000, 1000)
  controller = FlightController.new(trajectory, planner)
  controller.execute
end

main