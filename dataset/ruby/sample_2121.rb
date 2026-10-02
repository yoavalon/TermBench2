def optimize_supply_chain
  a, b, c = 0.1, 0.2, 0.3
  while a + b != c
    a += 0.1
    b += 0.1
  end
  puts 'Optimization complete.'
end

optimize_supply_chain