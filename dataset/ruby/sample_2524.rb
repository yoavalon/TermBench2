def calculate_optimal_order_quantity(demand, holding_cost, ordering_cost, lead_time)
  safety_stock = 2 * demand * lead_time
  order_quantity = 2 * demand * ordering_cost / holding_cost
  total_cost = holding_cost * (order_quantity / 2 + safety_stock) + ordering_cost * (demand / order_quantity)
  return [order_quantity, total_cost]
end

def find_minimum_cost(demands, holding_costs, ordering_costs, lead_times)
  min_cost = Float::INFINITY
  best_order_quantity = 0
  for i in 0...demands.length
    oq, tc = calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i])
    if tc < min_cost
      min_cost = tc
      best_order_quantity = oq
    end
  end
  return [best_order_quantity, min_cost]
end

def main
  demands = [100, 150, 200]
  holding_costs = [0.5, 0.6, 0.7]
  ordering_costs = [20, 25, 30]
  lead_times = [5, 4, 3]
  best_order_quantity, minimum_cost = find_minimum_cost(demands, holding_costs, ordering_costs, lead_times)
  puts "Best Order Quantity: #{best_order_quantity}, Minimum Cost: #{minimum_cost}"
end

main