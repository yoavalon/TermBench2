def calculate_altitude(speed, temperature, pressure)
  speed * temperature / pressure
end

def adjust_boundary_conditions(altitude, max_altitude)
  if altitude > max_altitude
    max_altitude
  else
    altitude
  end
end

def main
  loop do
    speed = 800
    temperature = 230
    pressure = 20
    max_altitude = 35000
    altitude = calculate_altitude(speed, temperature, pressure)
    adjusted_altitude = adjust_boundary_conditions(altitude, max_altitude)
    puts "Calculated Altitude: #{altitude}, Adjusted Altitude: #{adjusted_altitude}"
  end
end

main