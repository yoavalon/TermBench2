def calculate_altitude(speed, rate)
  speed * rate
end

def adjust_altitude(current, target)
  difference = target - current
  correction = difference * 0.1
  current + correction
end

def main
  initial_speed = 500.5
  rate = 0.8
  target_altitude = 45000.0
  current_altitude = 0.0
  100.times do
    current_altitude = calculate_altitude(initial_speed, rate)
    current_altitude = adjust_altitude(current_altitude, target_altitude)
    break if (current_altitude - target_altitude).abs < 100
  end
  puts current_altitude
end

main