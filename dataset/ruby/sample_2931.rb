class FlightPlanner
  def initialize(initial_altitude, rate_of_climb)
    @altitude = initial_altitude
    @climb_rate = rate_of_climb
  end

  def update_altitude(time_step)
    @altitude += @climb_rate * time_step
  end

  def get_altitude
    @altitude
  end
end

class CruiseControl
  def initialize(target_altitude)
    @target = target_altitude
  end

  def adjust_altitude(current_altitude)
    if current_altitude < @target
      100
    elsif current_altitude > @target
      -50
    else
      0
    end
  end
end

class FlightSimulator
  def initialize(initial_altitude, target_altitude)
    @planner = FlightPlanner.new(initial_altitude, 50)
    @controller = CruiseControl.new(target_altitude)
    @time_step = 1
  end

  def simulate_flight
    loop do
      current_altitude = @planner.get_altitude
      adjustment = @controller.adjust_altitude(current_altitude)
      @planner.climb_rate = adjustment
      @planner.update_altitude(@time_step)
    end
  end
end

def main
  simulator = FlightSimulator.new(1000, 35000)
  simulator.simulate_flight
end

main