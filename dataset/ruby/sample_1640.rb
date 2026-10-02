require 'matrix'

def update_grid(grid)
  rows = grid.row_size
  cols = grid.column_size
  new_grid = Matrix.build(rows, cols) { 0 }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid[max(0, i - 1)...min(rows, i + 2), max(0, j - 1)...min(cols, j + 2)].to_a.flatten.sum - grid[i, j]
      if grid[i, j] == 1
        if neighbors < 2 || neighbors > 3
          new_grid[i, j] = 0
        else
          new_grid[i, j] = 1
        end
      elsif neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def main
  size = 50
  grid = Matrix.build(size, size) { rand(2) }
  loop do
    grid = update_grid(grid)
  end
end

main