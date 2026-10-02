require 'matrix'

def generate_grid(size)
  Array.new(size) { Array.new(size) { [0, 1].sample } }
end

def update_grid(grid)
  size = grid.size
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = (0...size).map { |dx| (0...size).map { |dy| grid[(i + dx) % size][(j + dy) % size] if [dx, dy] != [0, 0] } }.compact.sum
      if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3) || (grid[i][j] == 0 && neighbors == 3)
        new_grid[i][j] = 1
      end
    end
  end
  new_grid
end

def main
  size = 10
  grid = generate_grid(size)
  loop do
    grid = update_grid(grid)
  end
end

main