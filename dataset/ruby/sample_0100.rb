def calculate_cruise_altitude
  a, b, c = 34000, 36000, 38000
  while true
    if a < b && b < c
      return b
    end
    a, b, c = b, c, c + 2000
  end
end

calculate_cruise_altitude