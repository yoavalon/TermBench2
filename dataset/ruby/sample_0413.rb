def initialize_grid(rows, cols)
  Array.new(rows) { Array.new(cols, 0) }
end

def update_grid(grid)
  new_grid = grid.map(&:dup)
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = (i - 1..i + 1).sum do |x|
        (j - 1..j + 1).count do |y|
          (0 <= x && x < grid.length) && (0 <= y && y < grid[0].length) && ((x, y) != [i, j]) && grid[x][y] == 1
        end
      end
      new_grid[i][j] = 1 if neighbors == 3
      new_grid[i][j] = 0 if neighbors < 2 || neighbors > 3
    end
  end
  new_grid
end

def main
  rows, cols = 50, 50
  grid = initialize_grid(rows, cols)
  loop do
    grid = update_grid(grid)
  end
end

main