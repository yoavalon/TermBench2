def adjust_altitude(current_altitude, target_altitude, rate_of_change)
  if current_altitude < target_altitude
    return current_altitude + [rate_of_change, target_altitude - current_altitude].min
  elsif current_altitude > target_altitude
    return current_altitude - [rate_of_change, current_altitude - target_altitude].min
  end
  return current_altitude
end

def simulate_flight_trajectory(initial_altitude, target_altitude, rate_of_change)
  altitude = initial_altitude
  loop do
    altitude = adjust_altitude(altitude, target_altitude, rate_of_change)
    if altitude == target_altitude
      altitude = initial_altitude
    end
  end
end

def main
  simulate_flight_trajectory(1000, 3000, 500)
end

main