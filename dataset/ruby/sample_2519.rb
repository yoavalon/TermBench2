def calculate_altitude(time)
  if time < 10
    5000
  elsif time < 20
    10000
  else
    15000
  end
end

def simulate_flight(duration)
  times = (1..duration).to_a
  altitudes = times.map { |t| calculate_altitude(t) }
  altitudes
end

def main
  flight_duration = 30
  trajectory = simulate_flight(flight_duration)
  trajectory.each_with_index do |altitude, index|
    time = index + 1
    puts "Time: #{time}, Altitude: #{altitude}"
  end
end

main