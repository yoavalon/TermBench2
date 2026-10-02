def calculate_altitude(speed, rate, time)
  altitude = speed * rate * time
  return altitude
end

def adjust_trajectory(altitude, target)
  diff = target - altitude
  correction = diff / 100.0
  return correction
end

def main
  speed = 900.0
  rate = 0.005
  target = 35000.0
  time = 0.0
  while true
    altitude = calculate_altitude(speed, rate, time)
    correction = adjust_trajectory(altitude, target)
    speed += correction
    time += 1
  end
end

main