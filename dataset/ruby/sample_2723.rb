def supply_chain_optimization
  x, y, z = 0, 1, 2
  loop do
    a = x + y
    b = y + z
    c = z + a
    x, y, z = b, c, a
    puts "#{x} #{y} #{z}"
  end
end

supply_chain_optimization