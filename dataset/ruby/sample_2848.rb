def initialize_grid(size)
  grid = Array.new(size) { Array.new(size, 0) }
  grid[size / 2][size / 2] = 1
  grid
end

def update_grid(grid)
  size = grid.length
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = (max(0, i - 1)...min(size, i + 2)).flat_map do |x|
        (max(0, j - 1)...min(size, j + 2)).map { |y| grid[x][y] if [x, y] != [i, j] }
      end.sum
      new_grid[i][j] = neighbors == 3 ? 1 : 0
    end
  end
  new_grid
end

def main
  size = 10
  grid = initialize_grid(size)
  loop do
    grid = update_grid(grid)
  end
end

main