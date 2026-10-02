require 'matrix'

def initialize_grid(size)
  Matrix.build(size, size) { rand(0..1) }
end

def evolve(grid)
  size = grid.row_count
  next_grid = Matrix.build(size, size) { 0 }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = grid.minor([i-1, i, i+1], [j-1, j, j+1]).to_a.flatten.sum - grid[i, j]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        next_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        next_grid[i, j] = 1
      else
        next_grid[i, j] = grid[i, j]
      end
    end
  end
  next_grid
end

def main
  grid_size = 100
  grid = initialize_grid(grid_size)
  loop do
    grid = evolve(grid)
  end
end

main