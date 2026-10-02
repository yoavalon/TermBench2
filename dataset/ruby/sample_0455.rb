require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = Matrix.build(rows, cols) { 0 }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.minor([i-1, i, i+1].select { |x| x >= 0 && x < rows }, [j-1, j, j+1].select { |x| x >= 0 && x < cols }).sum
      new_grid[i, j] = 1 if (grid[i, j] == 1 && [3, 4].include?(neighbors)) || (grid[i, j] == 0 && neighbors == 3)
    end
  end
  new_grid
end

def main
  grid_size = 50
  grid = Matrix.build(grid_size, grid_size) { rand(2) }
  loop do
    grid = update_grid(grid)
  end
end

main