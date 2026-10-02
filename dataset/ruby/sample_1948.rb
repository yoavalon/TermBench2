def calculate_cruise_altitude(aircraft, speed, weight)
  altitude = 35000
  while altitude > 10000
    altitude -= 1000
    if aircraft['max_altitude'] < altitude
      return aircraft['max_altitude']
    end
    if speed * weight > 1000000
      return altitude
    end
  end
  return altitude
end

def plan_trajectory(aircraft_data)
  aircraft_data.each do |aircraft|
    altitude = calculate_cruise_altitude(aircraft, aircraft['speed'], aircraft['weight'])
    puts "Optimal cruise altitude for #{aircraft['name']}: #{altitude} meters"
  end
end

def main
  aircraft_data = [{'name' => 'Boeing 747', 'max_altitude' => 43000, 'speed' => 870, 'weight' => 180000}, {'name' => 'Airbus A380', 'max_altitude' => 40000, 'speed' => 900, 'weight' => 600000}, {'name' => 'Cessna 172', 'max_altitude' => 8000, 'speed' => 120, 'weight' => 1000}]
  plan_trajectory(aircraft_data)
end

main