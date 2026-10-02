def calculate_altitude(speed, wind, max_altitude)
  [0, [max_altitude, speed - wind].min].max
end

def update_trajectory(alt, time, descent_rate)
  if alt > 0
    alt - descent_rate * time
  else
    0
  end
end

def main
  speed = 600
  wind = 50
  max_altitude = 30000
  descent_rate = 100
  time_step = 1
  current_altitude = calculate_altitude(speed, wind, max_altitude)
  while current_altitude > 0
    puts "Current Altitude: #{current_altitude}"
    current_altitude = update_trajectory(current_altitude, time_step, descent_rate)
  end
end

main if __FILE__ == $0