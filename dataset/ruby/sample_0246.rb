require 'matrix'

def initialize_grid(size)
  grid = Matrix.build(size, size) { 0 }
  grid[size / 2, size / 2] = 1
  grid
end

def apply_boundary_conditions(grid)
  size = grid.row_size
  (0...size).each do |i|
    grid[0, i] = 0
    grid[size - 1, i] = 0
    grid[i, 0] = 0
    grid[i, size - 1] = 0
  end
end

def update_grid(grid)
  new_grid = grid.dup
  size = grid.row_size
  (1...size - 1).each do |i|
    (1...size - 1).each do |j|
      neighbors = grid.minor(i - 1..i + 1, j - 1..j + 1).to_a.flatten.sum - grid[i, j]
      if grid[i, j] == 1
        new_grid[i, j] = neighbors < 2 || neighbors > 3 ? 0 : 1
      else
        new_grid[i, j] = neighbors == 3 ? 1 : 0
      end
    end
  end
  new_grid
end

def simulate(steps)
  size = 50
  grid = initialize_grid(size)
  apply_boundary_conditions(grid)
  steps.times do
    grid = update_grid(grid)
    apply_boundary_conditions(grid)
  end
  grid
end

def main
  steps = 100
  result = simulate(steps)
  puts result.to_a
end

main