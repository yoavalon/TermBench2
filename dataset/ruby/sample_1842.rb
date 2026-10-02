def simulate_thermo_state
  x, y, z = 0.0, 0.0, 0.0
  1000.times do |i|
    x += 0.0001
    y -= 0.0001
    z = (x + y) * 10000
  end
  z
end

simulate_thermo_state