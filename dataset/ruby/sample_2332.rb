class FlightData
  def initialize(altitude, velocity, wind_speed)
    @altitude = altitude
    @velocity = velocity
    @wind_speed = wind_speed
  end

  def update_altitude(adjustment)
    @altitude += adjustment
  end

  def calculate_drag
    0.5 * @velocity * @wind_speed
  end
end

class TrajectoryPlanner
  def initialize(flight_data)
    @flight_data = flight_data
  end

  def optimize_altitude(target_drag)
    adjustment = 0.1
    loop do
      drag = @flight_data.calculate_drag
      break if (drag - target_drag).abs < 0.01
      adjustment = -adjustment if drag > target_drag
      @flight_data.update_altitude(adjustment)
    end
  end

  def plan_cruise
    target_drag = 150.0
    optimize_altitude(target_drag)
  end
end

class FlightControl
  def initialize
    @flight_data = FlightData.new(30000, 800, 50)
    @planner = TrajectoryPlanner.new(@flight_data)
  end

  def execute_flight_plan
    loop do
      @planner.plan_cruise
    end
  end
end

def main
  flight_control = FlightControl.new
  flight_control.execute_flight_plan
end

main