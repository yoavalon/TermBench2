class Flight
  def initialize(altitude, trajectory)
    @altitude = altitude
    @trajectory = trajectory
  end

  def adjust_altitude
    if @altitude < 30000
      @altitude += 1000
      @trajectory << @altitude
      adjust_altitude
    elsif @altitude < 40000
      @altitude += 500
      @trajectory << @altitude
      adjust_altitude
    else
      @altitude += 100
      @trajectory << @altitude
      adjust_altitude
    end
  end
end

class CruisePlanner
  def plan(flight)
    if flight.altitude < 35000
      flight.adjust_altitude
      plan(flight)
    else
      cruise(flight)
    end
  end

  def cruise(flight)
    flight.altitude += 50
    flight.trajectory << flight.altitude
    cruise(flight)
  end
end

def main
  flight = Flight.new(10000, [10000])
  planner = CruisePlanner.new
  planner.plan(flight)
end

main