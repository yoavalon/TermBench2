class FlightPlanner
  def initialize(initial_altitude, target_altitude, rate_of_climb, max_altitude)
    @current_altitude = initial_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
    @max_altitude = max_altitude
  end

  def climb
    if @current_altitude < @target_altitude
      @current_altitude += @rate_of_climb
      if @current_altitude > @max_altitude
        @current_altitude = @max_altitude
      end
    end
  end

  def stabilize
    @current_altitude == @target_altitude
  end

  def plan_flight
    while !stabilize
      climb
    end
    @current_altitude
  end
end

class FlightData
  def initialize(altitudes)
    @altitudes = altitudes
  end

  def update_altitude(new_altitude)
    @altitudes << new_altitude
  end

  def get_altitudes
    @altitudes
  end
end

class FlightController
  def initialize(planner, data)
    @planner = planner
    @data = data
  end

  def execute_flight
    final_altitude = @planner.plan_flight
    @data.update_altitude(final_altitude)
    @data.get_altitudes
  end
end

def main
  initial_altitude = 5000
  target_altitude = 35000
  rate_of_climb = 1000
  max_altitude = 40000
  planner = FlightPlanner.new(initial_altitude, target_altitude, rate_of_climb, max_altitude)
  data = FlightData.new([initial_altitude])
  controller = FlightController.new(planner, data)
  altitudes = controller.execute_flight
  puts altitudes
end

main