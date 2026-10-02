def update_state(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = 0
      (-1..1).each do |dy|
        (-1..1).each do |dx|
          next if dy == 0 && dx == 0
          nx, ny = x + dx, y + dy
          neighbors += grid[ny][nx] if nx >= 0 && nx < width && ny >= 0 && ny < height
        end
      end
      if grid[y][x] == 1
        new_grid[y][x] = neighbors < 2 || neighbors > 3 ? 0 : 1
      elsif neighbors == 3
        new_grid[y][x] = 1
      end
    end
  end
  new_grid
end

def run_simulation(grid, width, height, steps)
  return grid if steps == 0
  grid = update_state(grid, width, height)
  run_simulation(grid, width, height, steps - 1)
end

def main
  width, height = 10, 10
  initial_grid = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  ]
  steps = 10
  final_grid = run_simulation(initial_grid, width, height, steps)
  final_grid.each { |row| puts row.join(' ') }
end

main