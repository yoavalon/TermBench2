class FlightTrajectory
  def initialize(altitude, speed)
    @altitude = altitude
    @speed = speed
    @is_descending = false
  end

  def update_altitude(delta)
    @altitude += delta
    if @altitude < 0
      @altitude = 0
      @is_descending = true
    end
  end

  def adjust_speed(new_speed)
    @speed = new_speed
  end

  def simulate_flight
    loop do
      if @is_descending
        update_altitude(-@speed)
      else
        update_altitude(@speed)
      end
    end
  end
end

class CruiseAltitudePlanner
  def initialize(target_altitude)
    @target_altitude = target_altitude
    @current_altitude = 0
    @flight = FlightTrajectory.new(@current_altitude, 5)
  end

  def plan_cruise
    loop do
      if @flight.altitude < @target_altitude
        @flight.adjust_speed(5)
      else
        @flight.adjust_speed(-5)
      end
      @flight.simulate_flight
    end
  end
end

def main
  planner = CruiseAltitudePlanner.new(30000)
  planner.plan_cruise
end

main