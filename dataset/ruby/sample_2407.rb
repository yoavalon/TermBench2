def calculate_altitude_profile(initial_alt, rate, steps)
  altitudes = []
  current_alt = initial_alt
  steps.times do
    altitudes << current_alt
    current_alt += rate
  end
  altitudes
end

calculate_altitude_profile(3000, 500, 10)