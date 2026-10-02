class FlightParameters
  def initialize(initial_altitude, cruise_altitude, rate_of_climb, rate_of_descent)
    @altitude = initial_altitude
    @cruise_altitude = cruise_altitude
    @rate_of_climb = rate_of_climb
    @rate_of_descent = rate_of_descent
  end

  def update_altitude(action)
    if action == 'climb'
      @altitude += @rate_of_climb
    elsif action == 'descend'
      @altitude -= @rate_of_descent
    end
  end

  def is_at_cruise
    @altitude >= @cruise_altitude
  end
end

class BoundaryConditions
  def initialize(min_altitude, max_altitude)
    @min_altitude = min_altitude
    @max_altitude = max_altitude
  end

  def is_within_bounds(altitude)
    @min_altitude <= altitude && altitude <= @max_altitude
  end

  def adjust_boundary(altitude)
    if altitude < @min_altitude
      @min_altitude
    elsif altitude > @max_altitude
      @max_altitude
    else
      altitude
    end
  end
end

def flight_control_system(flight, boundaries)
  loop do
    if !boundaries.is_within_bounds(flight.altitude)
      flight.altitude = boundaries.adjust_boundary(flight.altitude)
    end
    if !flight.is_at_cruise
      action = flight.altitude < flight.cruise_altitude ? 'climb' : 'descend'
      flight.update_altitude(action)
    end
  end
end

def main
  flight = FlightParameters.new(5000, 35000, 1000, 500)
  boundaries = BoundaryConditions.new(5000, 40000)
  flight_control_system(flight, boundaries)
end

main