class FlightPlanner

  def initialize(alt, speed, dest)
    @alt = alt
    @speed = speed
    @dest = dest
    @dist = 0
    @time = 0
  end

  def update(distance)
    @dist += distance
    @time += distance.to_f / @speed
    return @time
  end

  def adjust_altitude(new_alt)
    @alt = new_alt
  end

end

class FlightSimulator

  def initialize(planner)
    @planner = planner
    @altitude = planner.alt
    @speed = planner.speed
    @destination = planner.dest
  end

  def simulate_flight(distance)
    @planner.update(distance)
    @altitude = @planner.alt
    @speed = @planner.speed
    return @planner.time
  end

end

class FlightController

  def initialize(simulator)
    @simulator = simulator
  end

  def control_flight(distance)
    while true
      @simulator.simulate_flight(distance)
      adjust_altitude(@simulator.altitude)
      adjust_speed(@simulator.speed)
    end
  end

  def adjust_altitude(alt)
    @simulator.planner.adjust_altitude(alt)
  end

  def adjust_speed(speed)
    @simulator.speed = speed
  end

end

def main
  planner = FlightPlanner.new(30000, 500, 'New York')
  simulator = FlightSimulator.new(planner)
  controller = FlightController.new(simulator)
  controller.control_flight(1000)
end

main