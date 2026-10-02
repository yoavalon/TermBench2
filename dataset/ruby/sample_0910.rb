def simulate_state(a, b)
  x = a + b
  y = a * b
  simulate_state(x, y)
end

simulate_state(1, 1)