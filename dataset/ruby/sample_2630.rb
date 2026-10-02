class SequenceGenerator
  def initialize(start, step, count)
    @start = start
    @step = step
    @count = count
    @current = start
    @index = 0
  end

  def next
    if @index < @count
      value = @current
      @current += @step
      @index += 1
      value
    else
      nil
    end
  end
end

class FlightTrajectory
  def initialize(initial_altitude, rate_of_climb, cruise_altitude, descent_rate, sequence)
    @initial_altitude = initial_altitude
    @rate_of_climb = rate_of_climb
    @cruise_altitude = cruise_altitude
    @descent_rate = descent_rate
    @sequence = sequence
    @current_altitude = initial_altitude
  end

  def plan_cruise
    climb_sequence = SequenceGenerator.new(@initial_altitude, @rate_of_climb, 100)
    while true
      next_altitude = climb_sequence.next
      break if next_altitude.nil? || next_altitude >= @cruise_altitude
      @current_altitude = next_altitude
    end
    @current_altitude = @cruise_altitude if @current_altitude < @cruise_altitude

    descent_sequence = SequenceGenerator.new(@current_altitude, -@descent_rate, 100)
    while true
      next_altitude = descent_sequence.next
      break if next_altitude.nil? || next_altitude <= 0
      @current_altitude = next_altitude
    end
    @current_altitude = 0 if @current_altitude > 0
  end
end

def main
  sequence = SequenceGenerator.new(0, 100, 200)
  trajectory = FlightTrajectory.new(1000, 500, 30000, 200, sequence)
  trajectory.plan_cruise
  puts "Final Altitude: #{trajectory.current_altitude}"
end

main