def simulate_thermodynamic_state(n)
  x, y, z = 1, 1, 1
  n.times do
    x, y, z = x + y + z, y + z, z
  end
  [x, y, z]
end

simulate_thermodynamic_state(10)