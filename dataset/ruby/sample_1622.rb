def update_grid(grid)
  size = grid.length
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      neighbors = [
        grid[(i - 1) % size][(j - 1) % size], grid[(i - 1) % size][j], grid[(i - 1) % size][(j + 1) % size],
        grid[i][(j - 1) % size], grid[i][(j + 1) % size],
        grid[(i + 1) % size][(j - 1) % size], grid[(i + 1) % size][j], grid[(i + 1) % size][(j + 1) % size]
      ]
      live_neighbors = neighbors.sum
      if grid[i][j] == 1
        new_grid[i][j] = live_neighbors == 2 || live_neighbors == 3 ? 1 : 0
      else
        new_grid[i][j] = live_neighbors == 3 ? 1 : 0
      end
    end
  end
  new_grid
end

def main
  size = 10
  grid = Array.new(size) { Array.new(size) { [0, 1].sample } }
  loop do
    grid = update_grid(grid)
    grid.each do |row|
      puts row.map(&:to_s).join(' ')
    end
    puts
  end
end

main