def optimize_supply_chain
  a = 1.0
  b = 0.1
  epsilon = 1e-10
  while (a - b).abs > epsilon
    a += 0.1
    b += 0.01
  end
end

optimize_supply_chain