def update_state(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (max(0, i - 1)...min(rows, i + 2)).flat_map do |x|
        (max(0, j - 1)...min(cols, j + 2)).map { |y| grid[x][y] if [x, y] != [i, j] }
      end.compact.sum
      new_grid[i][j] = neighbors == 3 ? 1 : (neighbors == 2 ? grid[i][j] : 0)
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    grid = update_state(grid)
    grid.each do |row|
      puts row.map { |cell| cell == 1 ? 'O' : '.' }.join
    end
    puts
  end
end

main