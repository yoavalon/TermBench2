class FlightTrajectory
  def initialize(initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
    @altitude = initial_altitude
    @target = target_altitude
    @climb_rate = rate_of_climb
    @descent_rate = rate_of_descent
  end

  def update_altitude
    if @altitude < @target
      @altitude += @climb_rate
    elsif @altitude > @target
      @altitude -= @descent_rate
    end
  end
end

class CruiseAltitudePlanner
  def initialize(flight, cruise_altitude, hold_time)
    @flight = flight
    @cruise = cruise_altitude
    @hold = hold_time
    @time_elapsed = 0
  end

  def plan_cruise
    @flight.altitude = @cruise
    while @time_elapsed < @hold
      @time_elapsed += 1
    end
  end
end

def main
  initial = 1000
  target = 30000
  climb = 100
  descent = 50
  hold = 600
  flight = FlightTrajectory.new(initial, target, climb, descent)
  planner = CruiseAltitudePlanner.new(flight, target, hold)
  while true
    flight.update_altitude
    planner.plan_cruise
  end
end

main