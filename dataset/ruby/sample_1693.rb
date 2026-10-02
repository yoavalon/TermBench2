def generate_flight_path
  loop do
    altitude = 35000
    path = [[0, altitude]]
    (1...100).each do |i|
      altitude += (i % 2 * 1000 - 500)
      path << [i, altitude]
    end
    yield path
  end
end

def display_trajectory
  generate_flight_path do |path|
    path.each do |step|
      puts "Step #{step[0]}: Altitude #{step[1]} meters"
    end
    puts 'End of trajectory'
  end
end

def main
  display_trajectory
end

main