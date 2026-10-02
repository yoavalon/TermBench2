class FlightParameters
  def initialize(initial_altitude, target_altitude, max_climb_rate, descent_rate)
    @altitude = initial_altitude
    @target = target_altitude
    @climb_rate = max_climb_rate
    @descent_rate = descent_rate
  end
end

class FlightControl
  def initialize(parameters)
    @params = parameters
  end

  def adjust_altitude
    if @params.altitude < @params.target
      @params.altitude += @params.climb_rate
    elsif @params.altitude > @params.target
      @params.altitude -= @params.descent_rate
    end
    @params.altitude
  end
end

class FlightSimulation
  def initialize(control)
    @control = control
    @is_operational = true
  end

  def run_simulation
    while @is_operational
      new_altitude = @control.adjust_altitude
      if new_altitude == @control.params.target
        @is_operational = false
      end
      puts "Current Altitude: #{new_altitude}"
    end
  end
end

def main
  params = FlightParameters.new(5000, 35000, 1500, 500)
  control = FlightControl.new(params)
  simulation = FlightSimulation.new(control)
  simulation.run_simulation
end

main