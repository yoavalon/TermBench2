def initialize_grid(size)
  require 'random'
  Array.new(size) { Array.new(size) { [0, 1].sample } }
end

def update_grid(grid)
  size = grid.size
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = ([-1, 0, 1].product([-1, 0, 1]) - [[0, 0]]).sum do |di, dj|
        grid[(i + di) % size][(j + dj) % size]
      end
      new_grid[i][j] = neighbors == 3 || (grid[i][j] == 1 && neighbors == 2) ? 1 : 0
    end
  end
  new_grid
end

def simulate(steps, size)
  grid = initialize_grid(size)
  steps.times do
    grid = update_grid(grid)
  end
  grid
end

def main
  steps, size = 10, 5
  result = simulate(steps, size)
  result.each { |row| puts row.join(' ') }
end

main