def simulate_state(a, b)
  if a == b
    return a
  end
  if a < b
    return simulate_state(a + 1, b)
  end
  return simulate_state(a - 1, b)
end

simulate_state(0, 5)