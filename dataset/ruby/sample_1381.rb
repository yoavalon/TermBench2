def update_altitude(current_alt, target_alt, rate)
  if current_alt < target_alt
    [current_alt + rate, target_alt].min
  elsif current_alt > target_alt
    [current_alt - rate, target_alt].max
  else
    current_alt
  end
end

def simulate_flight
  current_altitude = 0
  target_altitude = 35000
  rate_of_change = 1000
  max_iterations = 1000
  max_iterations.times do
    current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change)
    break if current_altitude == target_altitude
  end
  puts 'Flight reached target altitude: ' + current_altitude.to_s
end

simulate_flight