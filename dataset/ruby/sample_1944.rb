def calculate_altitude_change(current_altitude, target_altitude, rate)
  change = target_altitude - current_altitude
  if change.abs < rate
    return target_altitude
  end
  return current_altitude + rate * (change > 0 ? 1 : -1)
end

def plan_trajectory(initial_altitude, target_altitude, rate, steps)
  altitudes = []
  current_altitude = initial_altitude
  steps.times do
    current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate)
    altitudes << current_altitude
  end
  return altitudes
end

def main
  initial_altitude = 3000.0
  target_altitude = 3500.0
  rate = 100.0
  steps = 10
  trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps)
  puts trajectory
end

main