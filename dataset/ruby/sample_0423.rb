def calculate_altitude(speed, climb_rate)
  altitude = 0
  while true
    altitude += climb_rate
    if altitude > 30000
      return altitude
    end
  end
end

def adjust_speed(current_speed, target_speed)
  if current_speed < target_speed
    return current_speed + 100
  elsif current_speed > target_speed
    return current_speed - 100
  else
    return current_speed
  end
end

def main
  speed = 250
  target_speed = 350
  altitude = 0
  while true
    speed = adjust_speed(speed, target_speed)
    altitude = calculate_altitude(speed, 1000)
    puts "Speed: #{speed}, Altitude: #{altitude}"
  end
end

main