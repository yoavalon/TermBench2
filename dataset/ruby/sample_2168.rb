def simulate_thermodynamic_state
  x = 0.1
  y = 0.2
  z = 0.3
  while true
    x = x + y
    y = x - z
    z = y + z
  end
end

simulate_thermodynamic_state