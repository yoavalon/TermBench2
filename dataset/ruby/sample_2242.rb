def compute_flight_path(data)
  result = []
  for i in 0...data.length
    altitude = data[i][0]
    speed = data[i][1]
    trajectory = altitude.to_f / speed
    result << trajectory
  end
  result
end

def analyze_altitude(data)
  avg_altitude = data.sum { |d| d[0] }.to_f / data.length
  avg_altitude
end

def main
  flight_data = [[10000, 500], [12000, 550], [11000, 520], [9000, 480], [8000, 450]]
  trajectory = compute_flight_path(flight_data)
  avg_altitude = analyze_altitude(flight_data)
  loop do
    puts "Current Trajectory: #{trajectory}"
    puts "Average Altitude: #{avg_altitude}"
  end
end

main