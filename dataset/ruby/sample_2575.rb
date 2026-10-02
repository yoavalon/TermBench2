def generate_altitude_sequence(start, end, step)
  sequence = []
  current = start
  while current <= end
    sequence << current
    current += step
  end
  sequence
end

def calculate_flight_duration(altitudes, speed)
  times = altitudes.map { |altitude| altitude.to_f / speed }
  times
end

def main
  start_altitude = 10000
  end_altitude = 40000
  step_size = 5000
  cruise_speed = 1000
  altitudes = generate_altitude_sequence(start_altitude, end_altitude, step_size)
  durations = calculate_flight_duration(altitudes, cruise_speed)
  altitudes.zip(durations).each do |altitude, duration|
    puts "Altitude: #{altitude}m, Duration: #{duration.round(2)}s"
  end
end

main