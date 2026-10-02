class FlightData
  def initialize(altitude, speed, heading)
    @altitude = altitude
    @speed = speed
    @heading = heading
  end

  def update_altitude(new_altitude)
    @altitude = new_altitude
  end

  def update_speed(new_speed)
    @speed = new_speed
  end

  def update_heading(new_heading)
    @heading = new_heading
  end
end

def calculate_new_altitude(current_altitude, target_altitude, step)
  if current_altitude < target_altitude
    [current_altitude + step, target_altitude].min
  else
    [current_altitude - step, target_altitude].max
  end
end

def calculate_new_speed(current_speed, target_speed, step)
  if current_speed < target_speed
    [current_speed + step, target_speed].min
  else
    [current_speed - step, target_speed].max
  end
end

def cruise_altitude_planning(flight, target_altitude, target_speed, step)
  while flight.altitude != target_altitude || flight.speed != target_speed
    flight.update_altitude(calculate_new_altitude(flight.altitude, target_altitude, step))
    flight.update_speed(calculate_new_speed(flight.speed, target_speed, step))
  end
end

def main
  initial_altitude = 10000
  initial_speed = 800
  initial_heading = 90
  target_altitude = 30000
  target_speed = 900
  step = 1000
  flight = FlightData.new(initial_altitude, initial_speed, initial_heading)
  cruise_altitude_planning(flight, target_altitude, target_speed, step)
  puts "Final altitude: #{flight.altitude}, Final speed: #{flight.speed}"
end

main