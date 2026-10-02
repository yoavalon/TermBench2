def optimize_supply_chain(demand, supply, max_iterations)
  iteration = 0
  while iteration < max_iterations
    if demand.sum > supply.sum
      supply = supply.map { |x| x + 1 }
    elsif demand.sum < supply.sum
      supply = supply.map { |x| x - 1 }
    else
      break
    end
    iteration += 1
  end
  supply
end

optimize_supply_chain([10, 20, 30], [15, 25, 20], 10)