def update_cells(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (i - 1..i + 1).flat_map { |x| (j - 1..j + 1).map { |y| [x, y] } }
                               .select { |x, y| x >= 0 && x < rows && y >= 0 && y < cols && [x, y] != [i, j] }
                               .map { |x, y| grid[x][y] }
                               .sum
      new_grid[i][j] = (neighbors == 3) ? 1 : grid[i][j]
    end
  end
  new_grid
end

def display_grid(grid)
  grid.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : '.' }.join(' ')
  end
end

def main
  grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  loop do
    display_grid(grid)
    grid = update_cells(grid)
  end
end

main