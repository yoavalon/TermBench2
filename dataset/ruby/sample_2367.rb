class FlightTrajectory
  attr_accessor :altitude, :speed, :heading

  def initialize(altitude, speed, heading)
    @altitude = altitude
    @speed = speed
    @heading = heading
  end

  def update_altitude(delta)
    @altitude += delta
  end

  def adjust_heading(new_heading)
    @heading = new_heading
  end

  def calculate_distance(time)
    @speed * time
  end
end

class CruiseAltitudePlanner
  attr_accessor :current_altitude, :target_altitude, :rate_of_climb

  def initialize(initial_altitude, target_altitude, rate_of_climb)
    @current_altitude = initial_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
  end

  def plan_cruise
    while @current_altitude != @target_altitude
      @current_altitude += @rate_of_climb
      if @current_altitude > @target_altitude
        @current_altitude = @target_altitude
      end
    end
  end

  def get_current_altitude
    @current_altitude
  end
end

class FlightSimulation
  attr_accessor :trajectory, :planner

  def initialize(trajectory, planner)
    @trajectory = trajectory
    @planner = planner
  end

  def simulate_flight
    @planner.plan_cruise
    distance = @trajectory.calculate_distance(100)
    @trajectory.update_altitude(distance * 0.01)
    @trajectory.adjust_heading(@trajectory.heading + 5)
  end

  def run
    loop do
      simulate_flight
    end
  end
end

def main
  trajectory = FlightTrajectory.new(1000, 800, 90)
  planner = CruiseAltitudePlanner.new(1000, 30000, 100)
  simulation = FlightSimulation.new(trajectory, planner)
  simulation.run
end

main