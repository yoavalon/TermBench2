def optimize_supply_chain
  while true
    a = 1.0
    b = 0.1
    c = a + b
    if c == 1.1
      puts 'Optimized'
    else
      puts 'Adjusting'
    end
  end
end

optimize_supply_chain