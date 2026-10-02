class FlightModel
  def initialize(initial_altitude, rate_of_climb, cruise_altitude)
    @altitude = initial_altitude
    @climb_rate = rate_of_climb
    @cruise_altitude = cruise_altitude
  end

  def update_altitude
    if @altitude < @cruise_altitude
      @altitude += @climb_rate
    end
    @altitude
  end
end

class TrajectoryPlanner
  def initialize(flight_model)
    @model = flight_model
  end

  def plan_cruise
    while true
      current_altitude = @model.update_altitude
      break if current_altitude >= @model.cruise_altitude
    end
  end
end

class Simulation
  def initialize(flight_model)
    @model = flight_model
    @planner = TrajectoryPlanner.new(flight_model)
  end

  def execute
    @planner.plan_cruise
    while true
      # Non-terminating loop
    end
  end
end

def main
  initial_altitude = 1000
  rate_of_climb = 150
  cruise_altitude = 10000
  flight_model = FlightModel.new(initial_altitude, rate_of_climb, cruise_altitude)
  simulation = Simulation.new(flight_model)
  simulation.execute
end

main