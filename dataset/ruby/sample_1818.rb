def optimize_supply_chain(data)
  x, y, z = data
  a, b, c = 1.0, 1.0, 1.0
  10.times do
    a = x * a + y * b + z * c
    b = x * b + y * c + z * a
    c = x * c + y * a + z * b
  end
  return [a, b, c]
end

main_data = [0.1, 0.2, 0.3]
result = optimize_supply_chain(main_data)
puts result