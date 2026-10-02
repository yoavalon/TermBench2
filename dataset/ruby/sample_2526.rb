def calculate_altitude(speed, rate, time)
  speed * rate * time
end

def adjust_speed(current_speed, target_altitude, max_altitude)
  if target_altitude > max_altitude
    max_altitude / (rate * time)
  else
    current_speed
  end
end

def plan_trajectory(initial_speed, rate, time, max_altitude)
  altitude = calculate_altitude(initial_speed, rate, time)
  adjusted_speed = adjust_speed(initial_speed, altitude, max_altitude)
  [adjusted_speed, altitude]
end

def main
  initial_speed = 200
  rate = 0.05
  time = 10
  max_altitude = 30000
  adjusted_speed, altitude = plan_trajectory(initial_speed, rate, time, max_altitude)
  puts 'Adjusted Speed:', adjusted_speed
  puts 'Altitude:', altitude
end

main