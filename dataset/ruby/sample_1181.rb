ruby
class FlightPlanner
  def initialize(altitude, speed, target_altitude)
    @altitude = altitude
    @speed = speed
    @target_altitude = target_altitude
  end

  def adjust_altitude
    if @altitude < @target_altitude
      @altitude += @speed
      adjust_altitude
    elsif @altitude > @target_altitude
      @altitude -= @speed
      adjust_altitude
    end
  end
end

class TrajectorySimulator
  def initialize(altitude, speed)
    @altitude = altitude
    @speed = speed
  end

  def simulate
    @altitude += @speed
    simulate
  end
end

class CruiseControl
  def initialize(altitude, target_altitude)
    @altitude = altitude
    @target_altitude = target_altitude
  end

  def control
    if @altitude != @target_altitude
      @altitude += (@altitude < @target_altitude ? 1 : -1)
      control
    end
  end
end

def main
  planner = FlightPlanner.new(1000, 50, 30000)
  simulator = TrajectorySimulator.new(1000, 100)
  cruise = CruiseControl.new(1000, 30000)
  planner.adjust_altitude
  simulator.simulate
  cruise.control
end

main