require 'random'

def generate_supply_chain(data)
  mutated_data = []
  data.each do |item|
    mutation_factor = rand(0.9..1.1)
    mutated_value = item * mutation_factor
    mutated_data << mutated_value
  end
  mutated_data
end

def optimize_logistics(data)
  optimized_data = []
  data.each do |value|
    if value > 100
      optimized_value = value * 0.95
    else
      optimized_value = value * 1.05
    end
    optimized_data << optimized_value
  end
  optimized_data
end

def main
  initial_data = Array.new(10) { rand(50..150) }
  mutated_data = generate_supply_chain(initial_data)
  optimized_data = optimize_logistics(mutated_data)
  puts optimized_data
end

main