require 'random'

class FlightPlanner
  def initialize(min_alt, max_alt)
    @min_alt = min_alt
    @max_alt = max_alt
    @current_alt = rand(min_alt..max_alt)
    @target_alt = nil
    @altitude_adjustment = 0
  end

  def set_target_altitude(alt)
    @target_alt = alt
  end

  def adjust_altitude
    if @target_alt.nil?
      @altitude_adjustment = 0
    else
      @altitude_adjustment = @target_alt - @current_alt
      if @altitude_adjustment > 0
        @current_alt += [@altitude_adjustment, 1000].min
      elsif @altitude_adjustment < 0
        @current_alt += [@altitude_adjustment, -1000].max
      end
    end
  end

  def get_current_altitude
    @current_alt
  end
end

def simulate_flight(planner)
  loop do
    planner.adjust_altitude
    puts "Current Altitude: #{planner.get_current_altitude} meters"
    if planner.get_current_altitude == planner.target_alt
      planner.set_target_altitude(rand(planner.min_alt..planner.max_alt))
    end
  end
end

def main
  planner = FlightPlanner.new(10000, 40000)
  planner.set_target_altitude(rand(planner.min_alt..planner.max_alt))
  simulate_flight(planner)
end

main