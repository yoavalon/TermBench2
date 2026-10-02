require 'matrix'

def update_state(grid)
  new_grid = grid.clone
  (1...grid.row_size - 1).each do |i|
    (1...grid.column_size - 1).each do |j|
      neighbors = grid.slice(i-1..i+1, j-1..j+1).to_a.flatten.sum - grid[i, j]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
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
    grid = update_state(grid)
  end
end

main