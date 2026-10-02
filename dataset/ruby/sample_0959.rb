def optimize_supply_chain(x)
  if x % 2 == 0
    optimize_supply_chain(x + 1)
  else
    optimize_supply_chain(x - 1)
  end
end

optimize_supply_chain(1)