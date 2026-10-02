require 'matrix'
require 'gnuplot'

def initialize_grid(size)
  grid = Matrix.build(size, size) { rand(2) }
end

def update_grid(grid)
  new_grid = grid.dup
  (1...grid.row_size - 1).each do |i|
    (1...grid.column_size - 1).each do |j|
      neighbors = grid.minor([i-1, i, i+1], [j-1, j, j+1]).to_a.sum - grid[i, j]
      if grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)
        new_grid[i, j] = 0
      elsif grid[i, j] == 0 && neighbors == 3
        new_grid[i, j] = 1
      end
    end
  end
  new_grid
end

def main
  grid_size = 100
  grid = initialize_grid(grid_size)
  Gnuplot.open do |gp|
    Gnuplot::Plot.new(gp) do |plot|
      plot.data << Gnuplot::DataSet.new([grid.to_a.flatten]) do |ds|
        ds.with = 'image'
        ds.notitle
      end
      while true
        grid = update_grid(grid)
        plot.data = Gnuplot::DataSet.new([grid.to_a.flatten]) do |ds|
          ds.with = 'image'
          ds.notitle
        end
        sleep(0.1)
      end
    end
  end
end

main