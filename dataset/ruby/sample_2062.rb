class FlightTrajectory

  def initialize(speed, altitude, distance)
    @speed = speed
    @altitude = altitude
    @distance = distance
  end

  def calculate_time
    @distance / @speed
  end

  def adjust_altitude(new_altitude)
    @altitude = new_altitude
  end

end

class CruiseAltitudePlanner

  def initialize(max_altitude, min_altitude, step)
    @max_altitude = max_altitude
    @min_altitude = min_altitude
    @step = step
  end

  def suggest_altitudes
    altitudes = []
    current = @min_altitude
    while current <= @max_altitude
      altitudes << current
      current += @step
    end
    altitudes
  end

end

def optimize_flight_plan(trajectory, planner)
  altitudes = planner.suggest_altitudes
  best_time = Float::INFINITY
  best_altitude = nil
  altitudes.each do |altitude|
    trajectory.adjust_altitude(altitude)
    time = trajectory.calculate_time
    if time < best_time
      best_time = time
      best_altitude = altitude
    end
  end
  trajectory.adjust_altitude(best_altitude)
  [trajectory.altitude, trajectory.calculate_time]
end

def main
  trajectory = FlightTrajectory.new(800, 30000, 1000)
  planner = CruiseAltitudePlanner.new(40000, 20000, 5000)
  best_altitude, best_time = optimize_flight_plan(trajectory, planner)
  puts "Best Altitude: #{best_altitude} meters"
  puts "Time to Destination: #{best_time} hours"
end

main