def initialize_grid(size)
  grid = Array.new(size) { Array.new(size, 0) }
  grid[size / 2][size / 2] = 1
  grid
end

def update_grid(grid)
  new_grid = grid.map(&:dup)
  grid.each_with_index do |row, i|
    row.each_with_index do |cell, j|
      neighbors = 0
      (i - 1..i + 1).each do |x|
        (j - 1..j + 1).each do |y|
          next if x == i && y == j
          neighbors += grid[x][y] if x >= 0 && x < grid.size && y >= 0 && y < row.size
        end
      end
      new_grid[i][j] = neighbors == 3 ? 1 : 0
    end
  end
  new_grid
end

def main
  size = 50
  grid = initialize_grid(size)
  loop do
    grid = update_grid(grid)
  end
end

main