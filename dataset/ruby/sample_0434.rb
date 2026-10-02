def update_cell(state, neighbors)
  active_neighbors = neighbors.sum
  if state == 1
    return 1 if [2, 3].include?(active_neighbors) else 0
  else
    return 1 if active_neighbors == 3 else 0
  end
end

def simulate(grid)
  rows, cols = grid.length, grid[0].length
  new_grid = Array.new(rows) { Array.new(cols, 0) }
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = []
      [-1, 0, 1].each do |x|
        [-1, 0, 1].each do |y|
          next if x == 0 && y == 0
          ni, nj = i + x, j + y
          neighbors << grid[ni][nj] if ni.between?(0, rows - 1) && nj.between?(0, cols - 1)
        end
      end
      new_grid[i][j] = update_cell(grid[i][j], neighbors)
    end
  end
  new_grid
end

def main
  grid = [[0, 1, 0, 0, 0], [0, 0, 1, 0, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0], [0, 0, 0, 0, 0]]
  loop do
    grid = simulate(grid)
  end
end

main