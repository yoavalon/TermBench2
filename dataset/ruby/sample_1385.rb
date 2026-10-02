def simulate_temperature_change(initial_temp, rate, steps)
  temperatures = [initial_temp]
  steps.times do
    new_temp = temperatures.last + rate
    temperatures << new_temp
  end
  temperatures
end

def analyze_data(data)
  max_temp = data.max
  min_temp = data.min
  [max_temp, min_temp]
end

def main
  data = simulate_temperature_change(20, 2, 10)
  max_temp, min_temp = analyze_data(data)
  puts "#{max_temp} #{min_temp}"
end

main