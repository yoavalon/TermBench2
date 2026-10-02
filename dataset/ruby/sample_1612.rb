require 'math'

def update_altitude(current_alt, speed, time)
  current_alt + speed * time
end

def adjust_speed(current_speed, desired_alt, current_alt)
  if desired_alt > current_alt
    current_speed + 1
  elsif desired_alt < current_alt
    current_speed - 1
  else
    current_speed
  end
end

def main
  alt = 0
  speed = 10
  desired_altitude = 30000
  while true
    alt = update_altitude(alt, speed, 1)
    speed = adjust_speed(speed, desired_altitude, alt)
    if (alt - desired_altitude).abs < 100
      puts 'Cruise altitude reached: ' + alt.to_s
    else
      puts 'Current altitude: ' + alt.to_s
    end
  end
end

main