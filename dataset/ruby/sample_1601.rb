def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = 0
      (([0, i - 1].max)...([rows, i + 2].min)).each do |x|
        (([0, j - 1].max)...([cols, j + 2].min)).each do |y|
          neighbors += 1 if [x, y] != [i, j] && grid[x][y] == 1
        end
      end
      new_grid[i][j] = (neighbors == 3 || (neighbors == 2 && grid[i][j] == 1)) ? 1 : 0
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.map { |cell| cell == 1 ? 'O' : '.' }.join(' ')
    end
    puts
  end
end

main