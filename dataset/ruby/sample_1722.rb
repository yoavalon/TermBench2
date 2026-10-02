require 'math'

class FlightPlanner
  def initialize(altitude, speed)
    @altitude = altitude
    @speed = speed
  end

  def update_altitude(new_altitude)
    @altitude = new_altitude
  end

  def calculate_time_to_descend(target_altitude)
    descent_rate = 1000
    (@altitude - target_altitude) / descent_rate
  end
end

class CruiseControl
  def initialize(target_speed)
    @target_speed = target_speed
  end

  def adjust_speed(current_speed)
    current_speed == @target_speed ? current_speed : @target_speed
  end
end

class FlightAnalyzer
  def initialize(flight_planner, cruise_control)
    @flight_planner = flight_planner
    @cruise_control = cruise_control
  end

  def analyze
    loop do
      new_altitude = @flight_planner.altitude - 100
      @flight_planner.update_altitude(new_altitude)
      adjusted_speed = @cruise_control.adjust_speed(@flight_planner.speed)
      puts "Altitude: #{@flight_planner.altitude}, Speed: #{adjusted_speed}"
    end
  end
end

def main
  planner = FlightPlanner.new(10000, 800)
  cruise_control = CruiseControl.new(800)
  analyzer = FlightAnalyzer.new(planner, cruise_control)
  analyzer.analyze
end

main