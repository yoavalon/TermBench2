def simulate_thermodynamic_state
  x = 0.5
  loop do
    x = 3.9 * x * (1 - x)
    puts x
  end
end

simulate_thermodynamic_state