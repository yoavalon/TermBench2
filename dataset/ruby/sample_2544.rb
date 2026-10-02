def calculate_altitude_sequence(initial_altitude, increment, steps)
  sequence = []
  steps.times do |i|
    sequence << initial_altitude + i * increment
  end
  sequence
end

def find_optimal_cruise_altitude(altitudes, max_fuel_consumption)
  optimal_altitude = altitudes.max { |x, y| (x <= max_fuel_consumption) <=> (y <= max_fuel_consumption) }
  optimal_altitude
end

def main
  initial = 10000
  increment = 1000
  steps = 10
  max_fuel = 15000
  altitudes = calculate_altitude_sequence(initial, increment, steps)
  optimal_altitude = find_optimal_cruise_altitude(altitudes, max_fuel)
  puts optimal_altitude
end

main