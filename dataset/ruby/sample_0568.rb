class Flight
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

def boundary_check(flight, min_alt, max_alt)
  if flight.altitude < min_alt
    flight.update_altitude(min_alt)
  elsif flight.altitude > max_alt
    flight.update_altitude(max_alt)
  end
end

def cruise_control(flight, target_speed)
  if flight.speed < target_speed
    flight.update_speed(flight.speed + 1)
  elsif flight.speed > target_speed
    flight.update_speed(flight.speed - 1)
  end
end

def flight_simulation
  flight = Flight.new(10000, 500, 90)
  min_altitude = 5000
  max_altitude = 30000
  target_speed = 600
  while true
    boundary_check(flight, min_altitude, max_altitude)
    cruise_control(flight, target_speed)
  end
end

def main
  flight_simulation
end

main