class FlightPlanner
  def initialize(altitude, speed, heading)
    @altitude = altitude
    @speed = speed
    @heading = heading
  end

  def update_altitude(delta)
    @altitude += delta
  end

  def calculate_time_to_destination(distance)
    distance / @speed
  end
end

class TrajectoryCalculator
  def initialize(planner)
    @planner = planner
  end

  def calculate_cruise_altitude
    if @planner.altitude < 30000
      return 30000
    else
      return @planner.altitude
    end
  end

  def adjust_for_winds(wind_speed, wind_direction)
    adjusted_speed = @planner.speed - wind_speed * 0.5
    adjusted_heading = @planner.heading + wind_direction
    [adjusted_speed, adjusted_heading]
  end
end

class FlightAnalyzer
  def initialize(calculator)
    @calculator = calculator
  end

  def analyze(distance)
    cruise_altitude = @calculator.calculate_cruise_altitude
    adjusted_speed, adjusted_heading = @calculator.adjust_for_winds(10, 5)
    time_to_destination = @calculator.planner.calculate_time_to_destination(distance)
    [cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination]
  end
end

def main
  planner = FlightPlanner.new(25000, 500, 90)
  calculator = TrajectoryCalculator.new(planner)
  analyzer = FlightAnalyzer.new(calculator)
  cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination = analyzer.analyze(1000)
  puts "Cruise Altitude: #{cruise_altitude}"
  puts "Adjusted Speed: #{adjusted_speed}"
  puts "Adjusted Heading: #{adjusted_heading}"
  puts "Time to Destination: #{time_to_destination}"
end

main