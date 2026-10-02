require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = grid.dup
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.minor(i-1..i+1, j-1..j+1)
      alive_neighbors = neighbors.to_a.flatten.sum - grid[i, j]
      if grid[i, j] == 1 && (alive_neighbors < 2 || alive_neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && alive_neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def simulate(grid_size)
  grid = Matrix.build(grid_size, grid_size) { rand(2) }
  loop do
    grid = update_grid(grid)
    puts grid.inspect
  end
end

simulate(10)