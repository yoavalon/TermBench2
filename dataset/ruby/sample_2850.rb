require 'matrix'

def update_grid(grid)
  shape = [grid.row_count, grid.column_count]
  new_grid = Matrix.build(shape[0], shape[1]) { 0 }
  (0...shape[0]).each do |i|
    (0...shape[1]).each do |j|
      neighbors = grid.minor([i-1, i, i+1].compact, [j-1, j, j+1].compact).sum - grid[i, j]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      else
        new_grid[i, j] = grid[i, j]
      end
    end
  end
  new_grid
end

def simulate
  size = 100
  grid = Matrix.build(size, size) { [0, 1].sample }
  loop do
    grid = update_grid(grid)
  end
end

simulate