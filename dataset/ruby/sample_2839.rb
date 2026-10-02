require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_size, grid.column_size
  new_grid = Matrix.build(rows, cols) { 0 }
  (0...rows).each do |i|
    (0...cols).each do |j|
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

def main
  size = 10
  grid = Matrix.build(size, size) { rand(2) }
  loop do
    grid = update_grid(grid)
  end
end

main