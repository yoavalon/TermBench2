def calculate_altitude(cruise_speed, distance, wind_speed, wind_direction)
  speed = wind_direction == 'against' ? cruise_speed - wind_speed : cruise_speed + wind_speed
  time = distance / speed
  altitude = cruise_speed * time / 10
  return altitude
end

def adjust_altitude(altitude, adjustments)
  adjustments.each do |adjustment|
    if adjustment > 0
      altitude += adjustment
    else
      altitude -= adjustment.abs
    end
  end
  return altitude
end

def main
  cruise_speed = 800
  distance = 2000
  wind_speed = 50
  wind_direction = 'against'
  adjustments = [100, -50, 30]
  initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction)
  final_altitude = adjust_altitude(initial_altitude, adjustments)
  puts final_altitude
end

main