class FlightPlanner
  def initialize(initial_altitude, target_altitude, altitude_step, descent_rate)
    @current_altitude = initial_altitude
    @target_altitude = target_altitude
    @altitude_step = altitude_step
    @descent_rate = descent_rate
  end

  def adjust_altitude
    if @current_altitude > @target_altitude
      @current_altitude -= @altitude_step
      if @current_altitude < @target_altitude
        @current_altitude = @target_altitude
      end
    else
      @current_altitude += @altitude_step
      if @current_altitude > @target_altitude
        @current_altitude = @target_altitude
      end
    end
  end

  def simulate_flight
    while @current_altitude != @target_altitude
      adjust_altitude
    end
    @current_altitude
  end
end

class TrajectoryAnalyzer
  def initialize(initial_position, target_position, position_step, direction)
    @current_position = initial_position
    @target_position = target_position
    @position_step = position_step
    @direction = direction
  end

  def update_position
    if @current_position < @target_position
      @current_position += @position_step
    elsif @current_position > @target_position
      @current_position -= @position_step
    end
  end

  def analyze_trajectory
    while @current_position != @target_position
      update_position
    end
    @current_position
  end
end

def main
  altitude_planner = FlightPlanner.new(30000, 35000, 1000, 500)
  trajectory_analyzer = TrajectoryAnalyzer.new(0, 1000, 100, 1)
  final_altitude = altitude_planner.simulate_flight
  final_position = trajectory_analyzer.analyze_trajectory
  puts "Final Altitude: #{final_altitude}"
  puts "Final Position: #{final_position}"
end

main