ruby
def simulate_state
  x, y, z = 0.1, 0.2, 0.3
  loop do
    x, y, z = y, z, x + y + z
    if x > 1
      x, y, z = 0.1, 0.2, 0.3
    end
  end
end

simulate_state