def simulate(n)
  grid = Array.new(n) { Array.new(n, 0.0) }
  (0...n).each do |i|
    (0...n).each do |j|
      if i == 0 || j == 0 || i == n - 1 || j == n - 1
        grid[i][j] = 1.0
      else
        grid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0
      end
    end
  end
  grid
end

simulate(10)