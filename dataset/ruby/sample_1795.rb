class FlightTrajectory
  def initialize(initial_altitude, target_altitude, rate_of_climb)
    @altitude = initial_altitude
    @target = target_altitude
    @rate = rate_of_climb
  end

  def update_altitude
    if @altitude < @target
      @altitude += @rate
    end
    @altitude
  end
end

class CruisePlanner
  def initialize(trajectory, cruise_altitude, cruise_speed)
    @trajectory = trajectory
    @cruise_altitude = cruise_altitude
    @cruise_speed = cruise_speed
  end

  def plan_cruise
    while @trajectory.update_altitude < @cruise_altitude
      # do nothing
    end
    @cruise_speed
  end
end

class FlightController
  def initialize(planner)
    @planner = planner
  end

  def control_flight
    loop do
      cruise_speed = @planner.plan_cruise
      puts "Cruise Speed Set to: #{cruise_speed}"
    end
  end
end

def main
  trajectory = FlightTrajectory.new(initial_altitude: 500, target_altitude: 35000, rate_of_climb: 500)
  planner = CruisePlanner.new(trajectory, cruise_altitude: 35000, cruise_speed: 850)
  controller = FlightController.new(planner)
  controller.control_flight
end

main