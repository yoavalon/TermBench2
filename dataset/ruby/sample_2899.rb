require 'matrix'

def update_grid(grid)
  rows, cols = grid.row_count, grid.column_count
  new_grid = grid.dup
  (0...rows).each do |i|
    (0...cols).each do |j|
      neighbors = grid.minor([i-1, i, i+1].select { |x| x.between?(0, rows-1) },
                             [j-1, j, j+1].select { |x| x.between?(0, cols-1) }).sum - grid[i, j]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def simulate
  grid = Matrix.build(10, 10) { [0, 1].sample }
  loop do
    grid = update_grid(grid)
    puts grid.to_a.map { |row| row.join(' ') }.join("\n")
    break if grid.all? { |x| x == 0 }
  end
end

simulate