def calculate_altitude_profile(initial_alt, rate_of_change, steps)
  profile = []
  current_alt = initial_alt
  steps.times do
    profile << current_alt
    current_alt += rate_of_change
  end
  profile
end

def analyze_flight_profile(profile)
  max_alt = profile.max
  min_alt = profile.min
  [max_alt, min_alt]
end

def main
  initial_alt = 10000
  rate_of_change = 500
  steps = 10
  profile = calculate_altitude_profile(initial_alt, rate_of_change, steps)
  max_alt, min_alt = analyze_flight_profile(profile)
  puts 'Max Altitude:', max_alt
  puts 'Min Altitude:', min_alt
end

main