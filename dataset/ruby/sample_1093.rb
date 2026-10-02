def update_state(grid, x, y, size)
  if x < 0 || x >= size || y < 0 || y >= size
    return grid
  end
  neighbors = 0
  (-1..1).each do |i|
    (-1..1).each do |j|
      next if i == 0 && j == 0
      nx, ny = x + i, y + j
      neighbors += grid[nx][ny] if nx >= 0 && nx < size && ny >= 0 && ny < size
    end
  end
  if grid[x][y] == 1
    grid[x][y] = 0 if neighbors < 2 || neighbors > 3
  else
    grid[x][y] = 1 if neighbors == 3
  end
  if x < size - 1
    update_state(grid, x + 1, y, size)
  elsif y < size - 1
    update_state(grid, 0, y + 1, size)
  else
    grid
  end
end

def main
  size = 10
  grid = Array.new(size) { Array.new(size, 0) }
  grid[size / 2][size / 2] = 1
  loop do
    grid = update_state(grid, 0, 0, size)
  end
end

main