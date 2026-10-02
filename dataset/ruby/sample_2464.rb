def simulate_thermodynamic_states(n)
  states = []
  for i in 0...n
    state = i ** 2 + 2 * i + 1
    states << state
  end
  return states
end

result = simulate_thermodynamic_states(10)
puts result