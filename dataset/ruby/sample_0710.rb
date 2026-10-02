def update_grid(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = (i-1..i+1).sum do |x|
        (j-1..j+1).sum do |y|
          next 0 if x == i && y == j
          next 0 if x < 0 || x >= rows || y < 0 || y >= cols
          grid[x][y]
        end
      end
      new_grid[i][j] = (neighbors == 3) || (grid[i][j] && neighbors == 2) ? 1 : 0
    end
  end
  new_grid
end

def simulate(grid, steps)
  steps.times do
    grid = update_grid(grid)
  end
  grid
end

def main
  initial_grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  steps = 5
  final_grid = simulate(initial_grid, steps)
  final_grid.each do |row|
    puts row.join(' ')
  end
end

main