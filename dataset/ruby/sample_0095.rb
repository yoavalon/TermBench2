def optimize_supply_chain(demand, supply, max_iterations)
  max_iterations.times do
    if demand > supply
      supply += 1
    elsif demand < supply
      supply -= 1
    else
      break
    end
  end
  supply
end

result = optimize_supply_chain(100, 90, 10)
puts result