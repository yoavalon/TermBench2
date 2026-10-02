def calculate_altitude_change(current_alt, target_alt, rate)
  if current_alt < target_alt
    [current_alt + rate, target_alt].min
  else
    [current_alt - rate, target_alt].max
  end
end

def simulate_flight_trajectory(initial_alt, target_alt, rate, steps)
  altitude = initial_alt
  trajectory = [altitude]
  steps.times do
    altitude = calculate_altitude_change(altitude, target_alt, rate)
    trajectory << altitude
    break if altitude == target_alt
  end
  trajectory
end

def main
  initial_altitude = 10000
  target_altitude = 30000
  rate_of_change = 1500
  simulation_steps = 100
  result = simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change, simulation_steps)
  puts result
end

main