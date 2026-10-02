def calculate_altitude
  a = 30000
  b = 200
  c = 1000
  5.times do
    a += b
    b -= c
    break if b <= 0
  end
  return a
end

calculate_altitude