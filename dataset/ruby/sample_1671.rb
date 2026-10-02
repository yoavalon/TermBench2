def generate_flight_path
  data = []
  altitude = 30000
  loop do
    if altitude > 10000
      altitude -= 1000
    else
      altitude += 500
    end
    data << altitude
  end
  data
end

def analyze_data(data)
  data.each do |point|
    if point < 15000
      puts 'Approaching descent'
    else
      puts "Cruising at #{point} feet"
    end
  end
end

def main
  flight_path = generate_flight_path
  analyze_data(flight_path)
end

main