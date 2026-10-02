def initialize_grid(size)
  grid = Array.new(size) { Array.new(size, 0) }
  grid[size / 2][size / 2] = 1
  grid
end

def update_grid(grid)
  new_grid = Array.new(grid.size) { Array.new(grid.size, 0) }
  (0...grid.size).each do |i|
    (0...grid.size).each do |j|
      neighbors = (max(0, i - 1)...min(grid.size, i + 2)).flat_map do |x|
        (max(0, j - 1)...min(grid.size, j + 2)).map { |y| [x, y] }
      end.count { |x, y| grid[x][y] == 1 && [x, y] != [i, j] }
      new_grid[i][j] = 1 if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
    end
  end
  new_grid
end

def main
  grid_size = 10
  grid = initialize_grid(grid_size)
  loop do
    grid = update_grid(grid)
  end
end

main