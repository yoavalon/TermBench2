def simulate_thermodynamic_state
  state = {temperature: 300, pressure: 1}
  loop do
    state[:temperature] += rand(-10.0..10.0)
    state[:pressure] += rand(-0.1..0.1)
    puts state
  end
end

simulate_thermodynamic_state