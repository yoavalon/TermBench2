def optimize_supply_chain(costs, index, result)
  if index == costs.length
    return result
  end
  min_cost = costs[index].min
  return optimize_supply_chain(costs, index + 1, result + min_cost)
end

costs = [[10, 20, 30], [15, 25, 35], [5, 15, 25]]
puts optimize_supply_chain(costs, 0, 0)