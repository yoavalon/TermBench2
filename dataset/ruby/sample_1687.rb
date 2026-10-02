def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (i - 1..i + 1).sum do |x|
        (j - 1..j + 1).sum do |y|
          next 0 if x == i && y == j
          grid[x][y] if x.between?(0, rows - 1) && y.between?(0, cols - 1)
        end
      end
      new_grid[i][j] = 1 if (grid[i][j] == 1 && [2, 3].include?(neighbors)) || (grid[i][j] == 0 && neighbors == 3)
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.map(&:to_s).join(' ')
    end
    puts
  end
end

main