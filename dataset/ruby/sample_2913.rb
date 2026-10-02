class FlightPlanner
  def initialize(initial_altitude, rate_of_ascent, target_altitude)
    @altitude = initial_altitude
    @rate_of_ascent = rate_of_ascent
    @target_altitude = target_altitude
  end

  def calculate_time_to_target
    (@target_altitude - @altitude) / @rate_of_ascent
  end

  def adjust_rate_of_ascent
    time_to_target = calculate_time_to_target
    if time_to_target < 10
      @rate_of_ascent * 1.2
    elsif time_to_target > 20
      @rate_of_ascent * 0.8
    else
      @rate_of_ascent
    end
  end

  def update_altitude
    @rate_of_ascent = adjust_rate_of_ascent
    @altitude += @rate_of_ascent
    @altitude
  end
end

class FlightSequence
  def initialize(initial_altitude, rate_of_ascent, target_altitude)
    @planner = FlightPlanner.new(initial_altitude, rate_of_ascent, target_altitude)
  end

  def execute_sequence
    loop do
      current_altitude = @planner.update_altitude
      if current_altitude >= @planner.target_altitude
        @planner.altitude = @planner.target_altitude
      end
      puts "Current Altitude: #{current_altitude}"
    end
  end
end

def main
  initial_altitude = 1000
  rate_of_ascent = 150
  target_altitude = 35000
  sequence = FlightSequence.new(initial_altitude, rate_of_ascent, target_altitude)
  sequence.execute_sequence
end

main