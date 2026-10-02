class FlightPlanner
  def initialize(initial_altitude, target_altitude, rate_of_climb)
    @current_altitude = initial_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
  end

  def calculate_climb_sequence
    sequence = []
    while @current_altitude < @target_altitude
      next_altitude = @current_altitude + @rate_of_climb
      sequence << next_altitude
      @current_altitude = next_altitude
    end
    sequence
  end

  def plan_trajectory
    sequence = calculate_climb_sequence
    trajectory = Array.new(sequence.length, 0)
    sequence.each_with_index do |altitude, i|
      trajectory[i] = altitude
    end
    trajectory
  end
end

class CruiseAltitudeManager
  def initialize(cruise_altitude, duration)
    @cruise_altitude = cruise_altitude
    @duration = duration
  end

  def generate_cruise_sequence
    sequence = Array.new(@duration, @cruise_altitude)
    sequence
  end
end

def main
  initial_altitude = 1000
  target_altitude = 35000
  rate_of_climb = 1000
  cruise_altitude = 35000
  duration = 100
  flight_planner = FlightPlanner.new(initial_altitude, target_altitude, rate_of_climb)
  climb_sequence = flight_planner.plan_trajectory
  cruise_manager = CruiseAltitudeManager.new(cruise_altitude, duration)
  cruise_sequence = cruise_manager.generate_cruise_sequence
  full_sequence = climb_sequence + cruise_sequence
  full_sequence.each do |altitude|
    puts altitude
  end
end

main