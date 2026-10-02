require 'matrix'

def initialize_grid(size)
  Array.new(size) { Array.new(size) { rand(0..1) } }
end

def update_grid(grid)
  size = grid.size
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = 0
      (-1..1).each do |x|
        (-1..1).each do |y|
          next if x == 0 && y == 0
          ni, nj = (i + x), (j + y)
          ni += size if ni < 0
          ni -= size if ni >= size
          nj += size if nj < 0
          nj -= size if nj >= size
          neighbors += grid[ni][nj]
        end
      end
      if grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)
        new_grid[i][j] = 1
      elsif grid[i][j] == 0 && neighbors == 3
        new_grid[i][j] = 1
      end
    end
  end
  new_grid
end

def main
  grid_size = 50
  grid = initialize_grid(grid_size)
  loop do
    grid = update_grid(grid)
  end
end

main