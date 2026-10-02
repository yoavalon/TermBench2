def fluid_dynamics(grid)
  size = grid.length
  next_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = 0
      (max(0, i - 1)...min(size, i + 2)).each do |x|
        (max(0, j - 1)...min(size, j + 2)).each do |y|
          neighbors += grid[x][y]
        end
      end
      next_grid[i][j] = neighbors > 4 ? 1 : 0
    end
  end
  fluid_dynamics(next_grid)
end

grid = Array.new(10) { Array.new(10, 0) }
grid[5][5] = 1
fluid_dynamics(grid)