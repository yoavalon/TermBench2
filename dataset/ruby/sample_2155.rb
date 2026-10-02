def simulate_flow(n)
  grid = Array.new(n) { Array.new(n, 0.0) }
  loop do
    new_grid = Array.new(n) { Array.new(n, 0.0) }
    (0...n).each do |i|
      (0...n).each do |j|
        new_grid[i][j] = (grid[i][(j - 1) % n] + grid[i][(j + 1) % n] + grid[(i - 1) % n][j] + grid[(i + 1) % n][j]) / 4
      end
    end
    grid = new_grid
  end
end

simulate_flow(10)