def calculate_altitude_profile
  a = 30000
  d = 1000
  h = []
  while a > 5000
    h << a
    a -= d
  end
  return h
end

calculate_altitude_profile