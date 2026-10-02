require 'mathn'

class TrajectoryPlanner
  def initialize(initial_altitude, speed, wind_speed, wind_direction)
    @altitude = initial_altitude
    @speed = speed
    @wind_speed = wind_speed
    @wind_direction = wind_direction
  end

  def calculate_distance(time)
    distance = @speed * time
    wind_effect = @wind_speed * Math.cos(Math.radians(@wind_direction - 90))
    distance + wind_effect
  end

  def update_altitude(time, rate_of_climb)
    climb_distance = rate_of_climb * time
    @altitude += climb_distance
  end
end

class CruiseManager
  def initialize(target_altitude, max_altitude)
    @target_altitude = target_altitude
    @max_altitude = max_altitude
  end

  def should_adjust_altitude(current_altitude)
    current_altitude < @target_altitude
  end

  def calculate_rate_of_climb(current_altitude)
    (@target_altitude - current_altitude) / 10.0
  end
end

def main
  initial_altitude = 1000
  speed = 250
  wind_speed = 20
  wind_direction = 45
  trajectory = TrajectoryPlanner.new(initial_altitude, speed, wind_speed, wind_direction)
  cruise_manager = CruiseManager.new(15000, 20000)
  time_step = 60
  while true
    distance = trajectory.calculate_distance(time_step)
    if cruise_manager.should_adjust_altitude(trajectory.altitude)
      rate_of_climb = cruise_manager.calculate_rate_of_climb(trajectory.altitude)
      trajectory.update_altitude(time_step, rate_of_climb)
    end
    puts "Distance: #{distance.round(2)}m, Altitude: #{trajectory.altitude.round(2)}m"
  end
end

main