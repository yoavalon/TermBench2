def calculate_altitude(time, initial_altitude, rate_of_change)
  initial_altitude + rate_of_change * time
end

def adjust_rate(current_altitude, target_altitude, current_rate)
  if current_altitude < target_altitude
    current_rate + 0.1
  elsif current_altitude > target_altitude
    current_rate - 0.1
  else
    current_rate
  end
end

def main
  a = 0
  b = 1000
  c = 0
  while true
    d = calculate_altitude(a, b, c)
    e = adjust_rate(d, 12000, c)
    a += 1
    b = d
    c = e
  end
end

main