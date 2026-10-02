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

class CruiseAltitudePlanner
  def initialize(trajectory, cruise_altitude)
    @trajectory = trajectory
    @cruise = cruise_altitude
  end

  def plan_cruise
    while @trajectory.altitude < @cruise
      @trajectory.update_altitude
    end
    @cruise
  end
end

class FlightControl
  def initialize(planner)
    @planner = planner
  end

  def execute_flight
    loop do
      cruise_altitude = @planner.plan_cruise
      puts "Cruise altitude reached: #{cruise_altitude} meters"
    end
  end
end

def main
  initial_altitude = 1000
  target_altitude = 8000
  rate_of_climb = 150
  cruise_altitude = 10000
  trajectory = FlightTrajectory.new(initial_altitude, target_altitude, rate_of_climb)
  planner = CruiseAltitudePlanner.new(trajectory, cruise_altitude)
  flight_control = FlightControl.new(planner)
  flight_control.execute_flight
end

main