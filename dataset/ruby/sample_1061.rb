def update_grid(grid)
  new_grid = Array.new(grid.length) { Array.new(grid[0].length, 0) }
  (0...grid.length).each do |i|
    (0...grid[0].length).each do |j|
      neighbors = []
      (-1..1).each do |di|
        (-1..1).each do |dj|
          ni, nj = i + di, j + dj
          neighbors << grid[ni][nj] if ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length
        end
      end
      new_grid[i][j] = neighbors.sum / neighbors.length
    end
  end
  new_grid
end

def display(grid)
  grid.each do |row|
    puts row.map(&:to_s).join(' ')
  end
  puts
end

def simulate(grid)
  display(grid)
  simulate(update_grid(grid))
end

def main
  grid = [[0, 1, 0], [1, 0, 1], [0, 1, 0]]
  simulate(grid)
end

main