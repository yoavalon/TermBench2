def optimize_supply_chain(data)
  total_cost = 0.0
  data.each do |item|
    total_cost += item['quantity'] * item['price']
  end
  total_cost.round(2)
end

def main
  data = [{'quantity' => 150.75, 'price' => 2.34}, {'quantity' => 200.5, 'price' => 1.8}, {'quantity' => 120.25, 'price' => 3.15}]
  result = optimize_supply_chain(data)
  puts result
end

main