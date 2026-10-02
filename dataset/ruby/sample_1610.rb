def calculate_altitude(speed, wind, temperature)
  base_altitude = 35000
  altitude_adjustment = (speed - 600) * 0.5 + (wind - 10) * -0.2 + (temperature - 20) * 0.1
  base_altitude + altitude_adjustment
end

def simulate_flight
  speed = 550
  wind = 5
  temperature = 15
  altitude = calculate_altitude(speed, wind, temperature)
  while true
    speed += 1
    wind += 0.1
    temperature -= 0.2
    altitude = calculate_altitude(speed, wind, temperature)
    if altitude < 30000
      speed -= 2
    elsif altitude > 40000
      speed -= 1
    end
    puts "Speed: #{speed}, Wind: #{wind}, Temperature: #{temperature}, Altitude: #{altitude}"
  end
end

simulate_flight