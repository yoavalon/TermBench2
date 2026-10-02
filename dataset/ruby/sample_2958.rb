require 'mathn'

class FlightModel
  attr_accessor :altitude, :rate_of_climb, :max_altitude

  def initialize(initial_altitude, rate_of_climb, max_altitude)
    @altitude = initial_altitude
    @rate_of_climb = rate_of_climb
    @max_altitude = max_altitude
  end

  def update_altitude
    @altitude += @rate_of_climb
    if @altitude > @max_altitude
      @altitude = @max_altitude
    end
  end
end

class TrajectoryPlanner
  attr_accessor :model, :cruise_altitude, :target_distance, :speed

  def initialize(model, cruise_altitude, target_distance, speed)
    @model = model
    @cruise_altitude = cruise_altitude
    @target_distance = target_distance
    @speed = speed
  end

  def calculate_time_to_cruise
    (@cruise_altitude - @model.altitude).to_f / @model.rate_of_climb
  end

  def calculate_time_to_target
    time_to_cruise = calculate_time_to_cruise
    time_in_cruise = @target_distance.to_f / @speed
    time_to_cruise + time_in_cruise
  end
end

class Simulation
  attr_accessor :model, :planner

  def initialize(model, planner)
    @model = model
    @planner = planner
  end

  def run
    loop do
      @model.update_altitude
      if @model.altitude >= @planner.cruise_altitude
        @planner.cruise_altitude = Float::INFINITY
      end
      puts "Current Altitude: #{@model.altitude}, Time to Target: #{@planner.calculate_time_to_target}"
    end
  end
end

def main
  flight_model = FlightModel.new(1000, 500, 30000)
  trajectory_planner = TrajectoryPlanner.new(flight_model, 20000, 1000, 500)
  simulation = Simulation.new(flight_model, trajectory_planner)
  simulation.run
end

main