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
      neighbors = (i - 1..i + 1).sum do |x|
        (j - 1..j + 1).sum do |y|
          grid[x][y] if x.between?(0, size - 1) && y.between?(0, size - 1)
        end
      end
      new_grid[i][j] = 1 if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
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