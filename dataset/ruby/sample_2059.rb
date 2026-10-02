class FlightPlanner

  def initialize(initial_altitude, target_altitude, speed, descent_rate)
    @altitude = initial_altitude
    @target = target_altitude
    @speed = speed
    @descent = descent_rate
    @time = 0
  end

  def update_altitude
    if @altitude > @target
      @altitude -= @descent * @speed
      @time += 1
    else
      @altitude = @target
    end
  end

  def get_flight_data
    [@altitude, @time]
  end

end

class TrajectoryAnalyzer

  def initialize(planner)
    @planner = planner
  end

  def analyze
    data = []
    while @planner.altitude > @planner.target
      @planner.update_altitude
      data << @planner.get_flight_data
    end
    data
  end

end

def main
  initial_altitude = 35000.0
  target_altitude = 10000.0
  speed = 0.5
  descent_rate = 100.0
  planner = FlightPlanner.new(initial_altitude, target_altitude, speed, descent_rate)
  analyzer = TrajectoryAnalyzer.new(planner)
  trajectory_data = analyzer.analyze
  trajectory_data.each do |altitude, time|
    puts "Time: #{time}, Altitude: #{altitude}"
  end
end

main if __FILE__ == $0