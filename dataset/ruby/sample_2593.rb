def calculate_trajectory(velocity, altitude, time)
  gravity = 9.81
  distance = velocity * time
  altitude_change = velocity * time - 0.5 * gravity * time ** 2
  return [distance, altitude + altitude_change]
end

def plan_cruise_altitude(initial_altitude, max_altitude, rate_of_climb, time)
  if initial_altitude < max_altitude
    new_altitude = initial_altitude + rate_of_climb * time
    return [new_altitude, max_altitude].min
  end
  return initial_altitude
end

def main
  velocity = 250
  altitude = 5000
  time = 3600
  max_altitude = 10000
  rate_of_climb = 500
  distance, new_altitude = calculate_trajectory(velocity, altitude, time)
  cruise_altitude = plan_cruise_altitude(new_altitude, max_altitude, rate_of_climb, time)
  puts "Distance covered: #{distance} meters"
  puts "New altitude: #{new_altitude} meters"
  puts "Cruise altitude: #{cruise_altitude} meters"
end

main if __FILE__ == $0