def update_cell(grid, i, j, size)
  neighbors = 0
  (i - 1).upto(i + 1) do |x|
    (j - 1).upto(j + 1) do |y|
      neighbors += grid[x][y] if x.between?(0, size - 1) && y.between?(0, size - 1) && !(x == i && y == j)
    end
  end
  neighbors == 3 || (grid[i][j] && neighbors == 2)
end

def step(grid)
  size = grid.length
  new_grid = Array.new(size) { Array.new(size, 0) }
  (0...size).each do |i|
    (0...size).each do |j|
      new_grid[i][j] = update_cell(grid, i, j, size)
    end
  end
  new_grid
end

def main
  size = 10
  grid = Array.new(size) { Array.new(size, 0) }
  grid[1][1], grid[2][2], grid[2][1] = [1, 1, 1]
  loop do
    grid = step(grid)
  end
end

main