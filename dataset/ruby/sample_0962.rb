def simulate_state(x, y)
  z = x + y
  simulate_state(z, x)
end

simulate_state(1, 1)