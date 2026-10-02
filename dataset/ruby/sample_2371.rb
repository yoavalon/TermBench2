class FlightPlan
  def initialize(altitude, speed, heading, duration)
    @altitude = altitude
    @speed = speed
    @heading = heading
    @duration = duration
  end

  def calculate_distance
    distance = @speed * @duration
    distance
  end

  def adjust_altitude(adjustment)
    @altitude += adjustment
  end
end

class TrajectoryAnalyzer
  def initialize(plan)
    @plan = plan
  end

  def analyze_cruise
    distance = @plan.calculate_distance
    adjusted_altitude = @plan.altitude + 0.5
    [distance, adjusted_altitude]
  end
end

class FlightController
  def initialize(analyzer)
    @analyzer = analyzer
  end

  def control_cruise
    loop do
      distance, altitude = @analyzer.analyze_cruise
      puts "Distance: #{distance.round(2)}, Altitude: #{altitude.round(2)}"
    end
  end
end

def main
  altitude = 30000.0
  speed = 500.0
  heading = 270
  duration = 5
  flight_plan = FlightPlan.new(altitude, speed, heading, duration)
  trajectory_analyzer = TrajectoryAnalyzer.new(flight_plan)
  flight_controller = FlightController.new(trajectory_analyzer)
  flight_controller.control_cruise
end

main