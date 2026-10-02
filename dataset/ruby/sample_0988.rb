def optimize_supply_chain(x, y)
  if x > y
    optimize_supply_chain(x - 1, y)
  elsif x < y
    optimize_supply_chain(x, y - 1)
  else
    optimize_supply_chain(x + 1, y + 1)
  end
end

optimize_supply_chain(1, 1)