def simulate_state
  x, y = 0, 1
  loop do
    x, y = y, x + y
  end
end

simulate_state