require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = Matrix.build(rows, cols) { 0.0 }
  (1...rows - 1).each do |i|
    (1...cols - 1).each do |j|
      neighbors = grid.minor(i-1, i+1, j-1, j+1)
      new_grid[i, j] = neighbors.to_a.flatten.sum - grid[i, j]
    end
  end
  new_grid
end

def simulate_flow(iterations)
  grid = Matrix.build(10, 10) { rand.to_f }
  iterations.times do
    grid = update_grid(grid)
  end
  grid
end

def main
  result = simulate_flow(100)
  puts result
end

main