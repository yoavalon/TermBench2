def simulate
  grid = Array.new(50) { Array.new(50, 0) }
  loop do
    new_grid = Array.new(50) { Array.new(50, 0) }
    (1...49).each do |i|
      (1...49).each do |j|
        neighbors = grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]
        new_grid[i][j] = neighbors == 2 ? 1 : 0
      end
    end
    grid = new_grid
  end
end

simulate