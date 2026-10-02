def init_grid(size)
  Array.new(size) { Array.new(size) { [0, 1].sample } }
end

def update_grid(grid)
  new_grid = grid.map(&:dup)
  (1...grid.size - 1).each do |i|
    (1...grid[i].size - 1).each do |j|
      neighbors = grid[i - 1..i + 1].map { |row| row[j - 1..j + 1] }.flatten.sum - grid[i][j]
      if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i][j] = 0
      elsif grid[i][j] == 0 && neighbors == 3
        new_grid[i][j] = 1
      end
    end
  end
  new_grid
end

def main
  size = 10
  grid = init_grid(size)
  loop do
    grid = update_grid(grid)
    puts grid.map { |row| row.join(' ') }.join("\n")
    puts '-' * 40
  end
end

main