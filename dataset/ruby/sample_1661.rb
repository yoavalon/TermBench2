def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (0...rows).sum do |x|
        (0...cols).sum do |y|
          (grid[x][y] if (x != i || y != j) && x.between?(0, rows - 1) && y.between?(0, cols - 1))
        end
      end
      new_grid[i][j] = 1 if neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)
    end
  end
  new_grid
end

def main
  initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    initial_grid = update_grid(initial_grid)
    initial_grid.each do |row|
      puts row.join
    end
    puts
  end
end

main