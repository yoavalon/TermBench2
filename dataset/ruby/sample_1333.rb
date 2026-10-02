require 'matrix'

def update_grid(grid)
  new_grid = grid.clone
  (1...grid.row_size - 1).each do |i|
    (1...grid.column_size - 1).each do |j|
      neighbors = grid.slice(i - 1, 3, j - 1, 3).to_a.flatten.sum - grid[i, j]
      if grid[i, j] != 0 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def simulate(grid, steps)
  steps.times do
    grid = update_grid(grid)
  end
  grid
end

def main
  size = 50
  grid = Matrix.build(size, size) { 0 }
  grid[20...25, 20...25] = Matrix.build(5, 5) { rand(2) }
  final_grid = simulate(grid, 100)
  puts final_grid.to_a.map { |row| row.join(' ') }.join("\n")
end

main