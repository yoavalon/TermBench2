ruby
class FlightTrajectory
  def initialize(initial_altitude, rate_of_change)
    @altitude = initial_altitude
    @rate = rate_of_change
  end

  def update_altitude
    @altitude += @rate
  end

  def get_altitude
    @altitude
  end
end

class CruisePlanner
  def initialize(target_altitude)
    @target = target_altitude
  end

  def evaluate_altitude(current_altitude)
    (@target - current_altitude).abs
  end

  def adjust_rate(rate, error)
    if error > 1000
      rate * 1.1
    elsif error < 500
      rate * 0.9
    else
      rate
    end
  end
end

class Simulation
  def initialize(trajectory, planner)
    @trajectory = trajectory
    @planner = planner
  end

  def run
    loop do
      current_altitude = @trajectory.get_altitude
      error = @planner.evaluate_altitude(current_altitude)
      if error < 10
        @trajectory.rate = 0
      else
        @trajectory.rate = @planner.adjust_rate(@trajectory.rate, error)
      end
      @trajectory.update_altitude
    end
  end
end

def main
  initial_altitude = 1000.0
  rate_of_change = 100.0
  target_altitude = 30000.0
  trajectory = FlightTrajectory.new(initial_altitude, rate_of_change)
  planner = CruisePlanner.new(target_altitude)
  simulation = Simulation.new(trajectory, planner)
  simulation.run
end

main