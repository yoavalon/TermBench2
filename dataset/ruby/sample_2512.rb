def calculate_altitude_profile(initial_altitude, rate_of_change, steps)
  altitude_profile = []
  current_altitude = initial_altitude
  steps.times do
    altitude_profile << current_altitude
    current_altitude += rate_of_change
  end
  altitude_profile
end

def analyze_flight_data(altitude_profile)
  max_altitude = altitude_profile.max
  min_altitude = altitude_profile.min
  average_altitude = altitude_profile.sum.to_f / altitude_profile.length
  [max_altitude, min_altitude, average_altitude]
end

def main
  initial_altitude = 30000
  rate_of_change = 500
  steps = 10
  altitude_profile = calculate_altitude_profile(initial_altitude, rate_of_change, steps)
  max_altitude, min_altitude, average_altitude = analyze_flight_data(altitude_profile)
  puts "#{max_altitude} #{min_altitude} #{average_altitude}"
end

main