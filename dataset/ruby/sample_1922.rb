require 'matrix'

def simulate_temperature_change(initial_temp, rate, steps)
  data = Array.new(steps, 0.0)
  (0...steps).each do |i|
    data[i] = initial_temp + i * rate
  end
  data
end

def analyze_data(data, threshold)
  data.each_index.select { |i| data[i] > threshold }
end

def main
  initial_temp = 300.0
  rate = 0.1
  steps = 1000
  threshold = 350.0
  data = simulate_temperature_change(initial_temp, rate, steps)
  indices = analyze_data(data, threshold)
  puts indices.inspect
end

main