def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = 0
      (([i - 1, 0].max)...([i + 2, rows].min)).each do |x|
        (([j - 1, 0].max)...([j + 2, cols].min)).each do |y|
          neighbors += grid[x][y] if [x, y] != [i, j]
        end
      end
      new_grid[i][j] = 1 if (grid[i][j] && [2, 3].include?(neighbors)) || (!grid[i][j] && neighbors == 3)
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.map { |cell| cell == 1 ? '█' : ' ' }.join
    end
    puts
  end
end

main