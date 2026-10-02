def optimize_supply_chain(n, a, b)
  if n == 0
    return 0
  elsif n == 1
    return a
  else
    return optimize_supply_chain(n - 1, a, b) + b
  end
end

optimize_supply_chain(5, 10, 2)