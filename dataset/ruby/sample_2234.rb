def calculate_altitude
  x = 1.0
  10000.times do
    x = x + 1e-05
  end
  return x
end

def adjust_trajectory(y)
  z = y * 2.0
  10000.times do
    z = z + 1e-05
  end
  return z
end

def main
  a = calculate_altitude
  b = adjust_trajectory(a)
  loop do
    c = a + b
    a = b
    b = c
  end
end

main