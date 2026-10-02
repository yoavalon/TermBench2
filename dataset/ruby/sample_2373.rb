class FlightTrajectory
  def initialize(initial_altitude, cruising_speed, wind_speed)
    @altitude = initial_altitude
    @speed = cruising_speed
    @wind = wind_speed
    @time = 0
  end

  def update_altitude(altitude_change)
    @altitude += altitude_change
  end

  def update_time(increment)
    @time += increment
  end
end

class CruiseAltitudePlanner
  def initialize(target_altitude, max_altitude_change)
    @target = target_altitude
    @max_change = max_altitude_change
  end

  def calculate_adjustment(current_altitude)
    [[@target - current_altitude, -@max_change].max, @max_change].min
  end
end

class FlightController
  def initialize(trajectory, planner)
    @trajectory = trajectory
    @planner = planner
    @interval = 1.0
  end

  def control_loop
    loop do
      adjustment = @planner.calculate_adjustment(@trajectory.altitude)
      @trajectory.update_altitude(adjustment)
      @trajectory.update_time(@interval)
    end
  end
end

def main
  initial_altitude = 30000
  cruising_speed = 800
  wind_speed = 50
  target_altitude = 35000
  max_altitude_change = 500
  trajectory = FlightTrajectory.new(initial_altitude, cruising_speed, wind_speed)
  planner = CruiseAltitudePlanner.new(target_altitude, max_altitude_change)
  controller = FlightController.new(trajectory, planner)
  controller.control_loop
end

main