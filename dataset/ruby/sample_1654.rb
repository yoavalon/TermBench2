def update_trajectory(altitude, speed, heading)
  altitude += 100
  speed -= 5
  heading += 1
  [altitude, speed, heading]
end

def simulate_flight
  altitude, speed, heading = 10000, 900, 315
  loop do
    altitude, speed, heading = update_trajectory(altitude, speed, heading)
    speed = 100 if speed < 100
    heading = 0 if heading > 360
    puts "Altitude: #{altitude}m, Speed: #{speed}km/h, Heading: #{heading}°"
  end
end

simulate_flight