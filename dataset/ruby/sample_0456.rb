def init_grid(size)
  Array.new(size) { |y| Array.new(size) { |x| (x != 0 && x != size - 1 && y != 0 && y != size - 1) ? 0 : 1 } }
end

def update_grid(grid)
  new_grid = grid.map(&:dup)
  (1...grid.size - 1).each do |y|
    (1...grid[0].size - 1).each do |x|
      neighbors = [(-1, 0), (1, 0), (0, -1), (0, 1)].map { |dy, dx| grid[y + dy][x + dx] }
      new_grid[y][x] = (neighbors.sum >= 2) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid)
  loop do
    grid = update_grid(grid)
  end
end

def main
  size = 10
  grid = init_grid(size)
  simulate(grid)
end

main