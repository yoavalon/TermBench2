require 'matrix'

def update_grid(grid, precision)
  size = grid.row_count
  new_grid = Matrix.build(size) { 0.0 }
  (1...size - 1).each do |i|
    (1...size - 1).each do |j|
      avg = grid.minor(i - 1, i + 2, j - 1, j + 2).to_a.flatten.reduce(:+) / 9.0
      new_grid[i, j] = avg.round(precision)
    end
  end
  new_grid
end

def run_simulation(steps, precision)
  grid_size = 10
  grid = Matrix.build(grid_size) { rand }
  steps.times do
    grid = update_grid(grid, precision)
  end
  grid
end

if __FILE__ == $0
  steps = 50
  precision = 3
  result = run_simulation(steps, precision)
  puts result.to_a.map { |row| row.join(' ') }.join("\n")
end