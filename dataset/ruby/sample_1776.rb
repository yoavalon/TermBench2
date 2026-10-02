def calculate_altitude_profile(cruise_altitude, max_altitude, step)
  altitude_list = []
  current_altitude = 0
  while current_altitude < max_altitude
    altitude_list << current_altitude
    if current_altitude < cruise_altitude
      current_altitude += step
    else
      current_altitude -= step
    end
  end
  altitude_list
end

def adjust_flight_path(altitude_profile, wind_factor)
  adjusted_profile = []
  altitude_profile.each do |altitude|
    adjusted_altitude = altitude + wind_factor
    adjusted_profile << adjusted_altitude
  end
  adjusted_profile
end

def optimize_trajectory(trajectory, target_altitude)
  optimized_trajectory = []
  trajectory.each do |altitude|
    if altitude < target_altitude
      optimized_trajectory << target_altitude
    else
      optimized_trajectory << altitude
    end
  end
  optimized_trajectory
end

def main
  cruise_altitude = 30000
  max_altitude = 40000
  step = 1000
  wind_factor = 500
  target_altitude = 35000
  altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step)
  adjusted_profile = adjust_flight_path(altitude_profile, wind_factor)
  optimized_trajectory = optimize_trajectory(adjusted_profile, target_altitude)
  puts optimized_trajectory
end

main