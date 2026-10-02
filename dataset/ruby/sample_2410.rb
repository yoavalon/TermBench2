def simulate_state(n)
  a, b = 0, 1
  n.times do
    a, b = b, a + b
  end
  a
end

simulate_state(10)