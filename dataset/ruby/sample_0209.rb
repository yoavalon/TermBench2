class FlightPlanner

  def initialize(altitude, velocity, target_altitude)
    @altitude = altitude
    @velocity = velocity
    @target_altitude = target_altitude
    @current_step = 0
  end

  def calculate_step
    if @altitude < @target_altitude
      @altitude += @velocity
      @current_step += 1
    else
      raise StopIteration
    end
  end

  def get_status
    [@altitude, @current_step]
  end

end

class BoundaryChecker

  def initialize(max_altitude, min_altitude)
    @max_altitude = max_altitude
    @min_altitude = min_altitude
  end

  def check_bounds(altitude)
    if altitude > @max_altitude || altitude < @min_altitude
      raise ValueError, 'Boundary conditions violated'
    end
  end

end

def main
  initial_altitude = 1000
  velocity = 200
  target_altitude = 3000
  max_altitude = 5000
  min_altitude = 500
  planner = FlightPlanner.new(initial_altitude, velocity, target_altitude)
  checker = BoundaryChecker.new(max_altitude, min_altitude)
  begin
    while true
      planner.calculate_step
      current_altitude, step_count = planner.get_status
      checker.check_bounds(current_altitude)
      puts "Step: #{step_count}, Altitude: #{current_altitude}"
    end
  rescue StopIteration, ValueError => e
    puts "Termination: #{e.message}"
  end
end

main if __FILE__ == $0