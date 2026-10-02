def calculate_pressure(temperature, volume)
  0.0821 * temperature / volume
end

def update_temperature(temp, heat_added, heat_capacity)
  temp + heat_added / heat_capacity
end

def main
  temp = 300
  vol = 22.4
  heat_cap = 25
  heat_added = 1000
  max_iterations = 10
  max_iterations.times do
    pressure = calculate_pressure(temp, vol)
    temp = update_temperature(temp, heat_added, heat_cap)
    puts "Pressure: #{pressure.round(2)} atm, Temperature: #{temp.round(2)} K"
  end
end

main