class FlightTrajectory
  def initialize(start_altitude, rate_of_climb, cruise_altitude, descent_rate)
    @altitude = start_altitude
    @climb_rate = rate_of_climb
    @cruise_altitude = cruise_altitude
    @descent_rate = descent_rate
    @state = 'climb'
  end

  def update_altitude
    if @state == 'climb'
      if @altitude < @cruise_altitude
        @altitude += @climb_rate
      else
        @state = 'cruise'
      end
    elsif @state == 'cruise'
      # pass
    elsif @state == 'descent'
      if @altitude > 0
        @altitude -= @descent_rate
      else
        @state = 'landed'
      end
    end
  end

  def check_state
    if @altitude >= @cruise_altitude && @state == 'climb'
      @state = 'cruise'
    elsif @altitude <= 0 && @state == 'descent'
      @state = 'landed'
    end
  end
end

def simulate_flight
  trajectory = FlightTrajectory.new(0, 500, 35000, 300)
  loop do
    trajectory.update_altitude
    trajectory.check_state
  end
end

def main
  simulate_flight
end

main