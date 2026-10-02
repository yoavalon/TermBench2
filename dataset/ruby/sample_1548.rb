def supply_chain_optimize
  a = 0
  loop do
    a += 1
    b = a % 10
    if b == 0
      puts "Optimization step #{a}"
    end
  end
end

supply_chain_optimize