def calculate_altitude_adjustment(altitude, target_altitude, max_change)
  if altitude > target_altitude
    return [max_change, target_altitude - altitude].min
  elsif altitude < target_altitude
    return [max_change, target_altitude - altitude].max
  end
  return 0
end

def update_flight_data(data, target_altitude, max_change)
  new_data = []
  data.each do |entry|
    altitude = entry['altitude']
    adjustment = calculate_altitude_adjustment(altitude, target_altitude, max_change)
    new_entry = {'time' => entry['time'], 'altitude' => altitude + adjustment}
    new_data << new_entry
  end
  return new_data
end

def main
  initial_data = [{'time' => 0, 'altitude' => 10000}, {'time' => 1, 'altitude' => 10200}, {'time' => 2, 'altitude' => 10100}]
  target_altitude = 10500
  max_change = 300
  updated_data = update_flight_data(initial_data, target_altitude, max_change)
  updated_data.each do |entry|
    puts entry
  end
end

main