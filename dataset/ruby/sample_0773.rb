def update_grid(grid, width, height)
  new_grid = Array.new(height) { Array.new(width, 0) }
  (0...height).each do |y|
    (0...width).each do |x|
      neighbors = (0...3).flat_map { |ny| (0...3).map { |nx| grid[[y-1,0].max+ny][[x-1,0].max+nx] } }.sum - grid[y][x]
      new_grid[y][x] = neighbors == 3 || (neighbors == 2 && grid[y][x] == 1) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid, width, height, steps)
  steps.times do
    grid = update_grid(grid, width, height)
  end
  grid
end

def main
  width, height = 10, 10
  steps = 5
  initial_grid = Array.new(height) { Array.new(width, 0) }
  initial_grid[5][5] = 1
  result = simulate(initial_grid, width, height, steps)
  result.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : ' ' }.join
  end
end

main