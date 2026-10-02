def simulate_state(x)
  x += 1
  simulate_state(x)
end

simulate_state(0)