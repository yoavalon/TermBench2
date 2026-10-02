def optimize_supply_chain
  while true
    a, b = 0, 1
    10.times do
      a, b = b, a + b
    end
    break if a > 100
  end
end

optimize_supply_chain