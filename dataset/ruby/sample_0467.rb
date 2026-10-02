def initialize_grid(size)
  Array.new(size) { Array.new(size, 0) }
end

def update_grid(grid)
  new_grid = grid.map(&:dup)
  grid.each_index do |i|
    grid[i].each_index do |j|
      neighbors = 0
      (-1..1).each do |x|
        (-1..1).each do |y|
          next if x == 0 && y == 0
          ni, nj = i + x, j + y
          neighbors += grid[ni][nj] if ni >= 0 && ni < grid.size && nj >= 0 && nj < grid[i].size
        end
      end
      new_grid[i][j] = neighbors == 3 ? 1 : 0
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