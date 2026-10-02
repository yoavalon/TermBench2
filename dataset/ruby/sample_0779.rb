def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = (-1..1).sum { |dy| (-1..1).sum { |dx| grid[(y + dy) % height][(x + dx) % width] if [dx, dy] != [0, 0] } }
      new_grid[y][x] = neighbors == 3 ? 1 : grid[y][x]
    end
  end
  new_grid
end

def simulate(grid, width, height, steps)
  return grid if steps == 0
  simulate(update_grid(grid, width, height), width, height, steps - 1)
end

def main
  width, height, steps = 10, 10, 5
  initial_grid = Array.new(height) { |y| Array.new(width) { |x| x != y ? 0 : 1 } }
  final_grid = simulate(initial_grid, width, height, steps)
  final_grid.each { |row| puts row.join(' ') }
end

main