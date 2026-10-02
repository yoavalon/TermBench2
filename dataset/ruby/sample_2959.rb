require 'mathn'

class FlightTrajectory
  attr_accessor :altitude, :speed, :distance, :time

  def initialize(initial_altitude, cruise_speed)
    @altitude = initial_altitude
    @speed = cruise_speed
    @distance = 0
    @time = 0
  end

  def update_altitude(rate_of_change)
    @altitude += rate_of_change * @time
  end

  def update_distance
    @distance += @speed * @time
  end
end

class TrajectoryPlanner
  attr_accessor :trajectory

  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan(duration)
    duration.times do
      @trajectory.time += 1
      @trajectory.update_altitude(0.01)
      @trajectory.update_distance
    end
  end
end

class FlightSimulator
  attr_accessor :planner

  def initialize(planner)
    @planner = planner
  end

  def run
    loop do
      @planner.plan(100)
      puts "Altitude: #{@planner.trajectory.altitude.round(2)}m, Distance: #{@planner.trajectory.distance.round(2)}m"
    end
  end
end

def main
  flight = FlightTrajectory.new(3000, 800)
  planner = TrajectoryPlanner.new(flight)
  simulator = FlightSimulator.new(planner)
  simulator.run
end

main