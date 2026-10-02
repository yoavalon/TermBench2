def optimize_supply_chain(n)
  a, b = 0, 1
  n.times do
    a, b = b, a + b
  end
  a
end

if __FILE__ == $0
  optimize_supply_chain(10)
end