require 'random'

def generate_supply_chain(data)
  data.each_index { |i| data[i] += rand(1..10) }
  data
end

def optimize_inventory(data)
  threshold = data.sum.to_f / data.length
  data.each_index { |i| data[i] = threshold.to_i if data[i] > threshold }
  data
end

def main
  data = Array.new(10) { rand(50..150) }
  data = generate_supply_chain(data)
  data = optimize_inventory(data)
  puts data.inspect
end

main