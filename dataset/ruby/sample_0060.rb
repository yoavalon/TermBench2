def optimize_supply_chain(data)
  total_cost = 0
  data.each do |item|
    cost = item['price'] * item['quantity']
    total_cost += cost
  end
  return total_cost
end

if __FILE__ == $0
  data = [{'price' => 10, 'quantity' => 5}, {'price' => 20, 'quantity' => 10}, {'price' => 15, 'quantity' => 3}]
  result = optimize_supply_chain(data)
  puts result
end