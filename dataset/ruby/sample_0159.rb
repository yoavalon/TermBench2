def evaluate_supply_chain(data, threshold)
  total_cost = data.select { |item| item['demand'] > threshold }.map { |item| item['cost'] }.sum
  return total_cost
end

def optimize_inventory(data, max_budget)
  data.each do |item|
    if item['cost'] > max_budget
      item['quantity'] = 0
    else
      item['quantity'] = max_budget / item['cost']
    end
  end
  return data
end

def main
  supply_data = [{'product' => 'A', 'cost' => 10, 'demand' => 100, 'quantity' => 0}, {'product' => 'B', 'cost' => 20, 'demand' => 200, 'quantity' => 0}, {'product' => 'C', 'cost' => 15, 'demand' => 150, 'quantity' => 0}]
  budget = 500
  threshold = 150
  supply_data = optimize_inventory(supply_data, budget)
  total_cost = evaluate_supply_chain(supply_data, threshold)
  puts total_cost
end

main