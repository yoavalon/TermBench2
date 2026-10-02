def simulate_thermodynamic_state
  x = 0.0
  loop do
    x += 0.0001
    y = 1 / x
    break if y == 0
  end
end

simulate_thermodynamic_state