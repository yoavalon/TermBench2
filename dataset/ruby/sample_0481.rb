def initialize_grid(size)
  Array.new(size) { Array.new(size, 0) }
end

def update_grid(grid)
  new_grid = grid.map(&:dup)
  rows = grid.size
  cols = grid[0].size
  (1...rows - 1).each do |i|
    (1...cols - 1).each do |j|
      neighbors = (i - 1..i + 1).map { |x| (j - 1..j + 1).map { |y| grid[x][y] } }.flatten.sum
      new_grid[i][j] = (neighbors == 3 || (grid[i][j] == 1 && neighbors == 2)) ? 1 : 0
    end
  end
  new_grid
end

def main
  size = 50
  grid = initialize_grid(size)
  loop do
    grid = update_grid(grid)
  end
end

main