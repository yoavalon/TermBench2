def simulate_state
  x, y = 1, 1
  loop do
    x, y = x + y, x - y
    if x == 0
      x, y = 1, 1
    end
  end
end

simulate_state