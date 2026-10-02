require 'matrix'

def initialize_grid(size)
  Matrix.build(size, size) { 0 }
end

def update_grid(grid)
  new_grid = grid.dup
  rows, cols = grid.row_count, grid.column_count
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.minor(i - 1..i + 1, j - 1..j + 1).to_a.flatten.sum - grid[i, j]
      if grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      elsif grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      end
    end
  end
  new_grid
end

def main
  grid_size = 50
  iterations = 100
  grid = initialize_grid(grid_size)
  iterations.times do
    grid = update_grid(grid)
  end
  puts grid.to_a
end

main if __FILE__ == $0