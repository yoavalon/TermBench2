def calculate_altitude(speed, rate, duration)
  total = 0.0
  loop do
    total += rate * duration
    yield total
  end
end

def adjust_rate(current_rate, target_altitude, current_altitude)
  if current_altitude < target_altitude
    current_rate + 0.1
  elsif current_altitude > target_altitude
    current_rate - 0.1
  else
    current_rate
  end
end

def main
  speed = 500.0
  rate = 100.0
  duration = 0.1
  target_altitude = 35000.0
  altitude_generator = calculate_altitude(speed, rate, duration)
  loop do
    current_altitude = altitude_generator.next
    rate = adjust_rate(rate, target_altitude, current_altitude)
  end
end

main