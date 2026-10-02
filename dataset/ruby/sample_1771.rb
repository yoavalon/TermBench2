class FlightTrajectory
  def initialize(initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
    @current_altitude = initial_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
    @rate_of_descent = rate_of_descent
  end

  def climb
    if @current_altitude < @target_altitude
      @current_altitude += @rate_of_climb
      if @current_altitude > @target_altitude
        @current_altitude = @target_altitude
      end
    end
  end

  def descend
    if @current_altitude > @target_altitude
      @current_altitude -= @rate_of_descent
      if @current_altitude < @target_altitude
        @current_altitude = @target_altitude
      end
    end
  end

  def adjust_altitude
    if @current_altitude < @target_altitude
      climb
    elsif @current_altitude > @target_altitude
      descend
    end
  end
end

class CruiseAltitudeManager
  def initialize(trajectory)
    @trajectory = trajectory
    @cruise_altitude = @trajectory.target_altitude
    @altitude_changes = []
  end

  def update_cruise_altitude(new_altitude)
    @cruise_altitude = new_altitude
    @trajectory.target_altitude = new_altitude
  end

  def log_altitude_change
    @altitude_changes << @trajectory.current_altitude
  end

  def manage_cruise
    @trajectory.adjust_altitude
    log_altitude_change
  end
end

class FlightSimulation
  def initialize(initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
    @trajectory = FlightTrajectory.new(initial_altitude, target_altitude, rate_of_climb, rate_of_descent)
    @cruise_manager = CruiseAltitudeManager.new(@trajectory)
  end

  def simulate_flight
    loop do
      @cruise_manager.manage_cruise
    end
  end
end

def main
  flight_sim = FlightSimulation.new(5000, 35000, 500, 300)
  flight_sim.simulate_flight
end

main