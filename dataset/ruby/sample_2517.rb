def update_grid(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = 0
      (-1..1).each do |di|
        (-1..1).each do |dj|
          next if di == 0 && dj == 0
          ni, nj = i + di, j + dj
          neighbors += grid[ni][nj] if ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length
        end
      end
      new_grid[i][j] = grid[i][j] == 1 ? (2 <= neighbors && neighbors <= 3 ? 1 : 0) : (neighbors == 3 ? 1 : 0)
    end
  end
  new_grid
end

def main
  initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  10.times do
    initial_grid = update_grid(initial_grid)
    initial_grid.each do |row|
      puts row.map { |cell| cell == 1 ? '#' : ' ' }.join
    end
    puts
  end
end

main