def simulate
  x, y, z = 1.0, 0.0, 0.0
  loop do
    x, y, z = y, z, 3.9 * x * (1 - x) + z
    yield [x, y, z]
  end
end

simulate.each do |state|
  puts state.inspect
end