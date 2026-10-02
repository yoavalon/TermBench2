def simulate_thermodynamic_states
  state = 0
  loop do
    state += 1
    energy = state ** 2
    pressure = energy + state
    puts "State: #{state}, Energy: #{energy}, Pressure: #{pressure}"
  end
end

simulate_thermodynamic_states