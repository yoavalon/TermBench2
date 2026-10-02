class FlightData
  def initialize(initial_altitude, target_altitude, rate_of_climb)
    @altitude = initial_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
  end

  def update_altitude
    if @altitude < @target_altitude
      @altitude += @rate_of_climb
    else
      @altitude = @target_altitude
    end
  end
end

class TrajectoryPlanner
  def initialize(data)
    @data = data
  end

  def plan_trajectory
    while @data.altitude < @data.target_altitude
      @data.update_altitude
      adjust_cruise_altitude
    end
  end

  def adjust_cruise_altitude
    if @data.altitude > 30000
      @data.rate_of_climb = 500
    elsif @data.altitude > 20000
      @data.rate_of_climb = 1000
    else
      @data.rate_of_climb = 1500
    end
  end
end

def main
  initial_altitude = 10000
  target_altitude = 40000
  rate_of_climb = 2000
  flight_data = FlightData.new(initial_altitude, target_altitude, rate_of_climb)
  trajectory_planner = TrajectoryPlanner.new(flight_data)
  trajectory_planner.plan_trajectory
  puts 'Final Altitude:', flight_data.altitude
end

main