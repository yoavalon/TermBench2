require 'matrix'

def update_grid(grid, size)
  new_grid = Matrix.build(size) { 0 }
  (1...size - 1).each do |i|
    (1...size - 1).each do |j|
      neighbors = grid.minor([i - 1, i, i + 1], [j - 1, j, j + 1]).to_a.flatten
      neighbors_sum = neighbors.sum - grid[i, j]
      if grid[i, j] == 0 && neighbors_sum > 2
        new_grid[i, j] = 1
      elsif grid[i, j] == 1 && (neighbors_sum < 2 || neighbors_sum > 3)
        new_grid[i, j] = 0
      else
        new_grid[i, j] = grid[i, j]
      end
    end
  end
  new_grid
end

def main
  size = 50
  grid = Matrix.build(size) { 0 }
  grid[size / 2, size / 2] = 1
  loop do
    grid = update_grid(grid, size)
  end
end

main