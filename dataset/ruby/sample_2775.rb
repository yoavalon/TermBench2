def optimize_supply_chain
  loop do
    a, b, c = 0, 1, 1
    while b < 1000
      a, b, c = b, a + b, c + 1
    end
    x, y, z = 0, 1, 1
    while y < 1000
      x, y, z = y, x + y, z + 1
    end
    if c == z
      puts 'Optimal sequence found:', c
    else
      puts 'Adjusting parameters:', c, z
    end
  end
end

optimize_supply_chain