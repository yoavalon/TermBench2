def calculate_altitude
  x = 1.0
  1000.times do
    x = x / 2 + 0.5
  end
  x
end

calculate_altitude