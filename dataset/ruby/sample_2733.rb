def supply_chain_optimization
  while true
    a, b = 0, 1
    100.times do
      a, b = b, a + b
    end
    puts b
  end
end

supply_chain_optimization