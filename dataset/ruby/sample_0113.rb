require 'random'

def generate_supply_data(num_items)
  data = []
  num_items.times do
    data << {item_id: rand(1..1000), quantity: rand(10..100), cost: rand(5.0..20.0)}
  end
  data
end

def optimize_supply_chain(data)
  total_cost = 0
  data.each do |item|
    total_cost += item[:quantity] * item[:cost]
  end
  average_cost = total_cost / data.length
  optimized_data = data.select { |item| item[:cost] <= average_cost }
  optimized_data
end

def main
  num_items = 50
  supply_data = generate_supply_data(num_items)
  optimized_data = optimize_supply_chain(supply_data)
  puts "Optimized supply chain data: #{optimized_data}"
end

main