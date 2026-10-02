def calculate_altitude(velocity, distance)
  g = 9.81
  (velocity ** 2 + 2 * g * distance) ** 0.5
end

def adjust_trajectory(altitude, speed)
  if altitude > 10000
    speed * 0.95
  else
    speed * 1.05
  end
end

def main
  velocity = 300
  distance = 10000
  altitude = calculate_altitude(velocity, distance)
  speed = adjust_trajectory(altitude, velocity)
  puts "Adjusted Speed: #{speed}"
end

main