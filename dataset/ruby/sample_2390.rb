class FlightPlanner

  def initialize(speed, altitude, distance)
    @speed = speed
    @altitude = altitude
    @distance = distance
  end

  def calculate_time
    @distance.to_f / @speed
  end

  def adjust_altitude(new_altitude)
    @altitude = new_altitude
  end

  def get_current_state
    [@speed, @altitude, @distance]
  end

end

class CruiseControl

  def initialize(planner)
    @planner = planner
  end

  def stabilize_altitude
    loop do
      current_altitude = @planner.altitude
      if current_altitude < 35000
        @planner.adjust_altitude(current_altitude + 1000)
      elsif current_altitude > 37000
        @planner.adjust_altitude(current_altitude - 1000)
      end
    end
  end

  def monitor_speed
    speed, _, _ = @planner.get_current_state
    if speed < 800
      @planner.speed += 10
    elsif speed > 900
      @planner.speed -= 10
    end
  end

end

class FlightSimulation

  def initialize
    @planner = FlightPlanner.new(850, 36000, 1000000)
    @control = CruiseControl.new(@planner)
  end

  def run_simulation
    loop do
      @control.stabilize_altitude
      @control.monitor_speed
      time = @planner.calculate_time
      puts "Speed: #{@planner.speed}, Altitude: #{@planner.altitude}, Time to Destination: #{'%.2f' % time} hours"
    end
  end

end

def main
  simulation = FlightSimulation.new
  simulation.run_simulation
end

main