def calculate_altitude_profile
  a, b, c = 3000, 2000, 1000
  loop do
    10.times do |i|
      puts "Altitude: #{a + i * (b - a) / 10.0}"
    end
    10.downto(1) do |i|
      puts "Altitude: #{b + i * (c - b) / 10.0}"
    end
  end
end

calculate_altitude_profile