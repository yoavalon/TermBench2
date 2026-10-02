require 'mathn'

class FlightTrajectory
  def initialize(initial_altitude, speed, angle, gravity, wind_speed)
    @a = initial_altitude
    @v = speed
    @t = angle
    @g = gravity
    @w = wind_speed
  end

  def calculate_time_to_cruise
    t = 2 * @a * Math.sin(@t) / @g
    t
  end

  def adjust_for_wind(time)
    adjusted_time = time / (1 + @w / @v)
    adjusted_time
  end
end

class CruiseAltitude
  def initialize(base_altitude, altitude_increment, max_altitude)
    @b = base_altitude
    @i = altitude_increment
    @m = max_altitude
  end

  def determine_cruise_altitude(time)
    alt = @b + @i * time
    alt > @m ? @m : alt
  end
end

def main
  initial_altitude = 1000.0
  speed = 250.0
  angle = Math.radians(30)
  gravity = 9.81
  wind_speed = 10.0
  base_altitude = 10000.0
  altitude_increment = 500.0
  max_altitude = 30000.0
  trajectory = FlightTrajectory.new(initial_altitude, speed, angle, gravity, wind_speed)
  cruise_altitude = CruiseAltitude.new(base_altitude, altitude_increment, max_altitude)
  loop do
    time = trajectory.calculate_time_to_cruise
    adjusted_time = trajectory.adjust_for_wind(time)
    current_altitude = cruise_altitude.determine_cruise_altitude(adjusted_time)
    puts "Current Altitude: #{current_altitude}"
  end
end

main