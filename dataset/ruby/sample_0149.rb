def calculate_cost(units, price, discount)
  if units > 100
    return units * price * (1 - discount)
  end
  return units * price
end

def optimize_supply_chain(demand, supply, cost_per_unit)
  if demand > supply
    shortage = demand - supply
    adjusted_cost = calculate_cost(shortage, cost_per_unit, 0.05)
    return adjusted_cost
  end
  return 0
end

def main()
  demand = 120
  supply = 100
  cost_per_unit = 10
  additional_cost = optimize_supply_chain(demand, supply, cost_per_unit)
  puts "Additional cost due to shortage: #{additional_cost}"
end

main()