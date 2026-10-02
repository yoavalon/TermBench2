def calculate_altitude(time)
  g = 9.80665
  v0 = 150.0
  h0 = 10000.0
  h0 - 0.5 * g * time ** 2 + v0 * time
end

def adjust_trajectory(current_time, target_altitude)
  current_altitude = calculate_altitude(current_time)
  altitude_difference = target_altitude - current_altitude
  if altitude_difference.abs < 100
    current_time
  else
    adjust_trajectory(current_time + 1, target_altitude)
  end
end

def main
  target = 5000.0
  start_time = 0
  final_time = adjust_trajectory(start_time, target)
  puts final_time
end

main