ruby
class FluidCell
  attr_accessor :value

  def initialize(value)
    @value = value
  end

  def update(neighbors)
    @value = neighbors.map(&:value).sum / neighbors.size.to_f
  end
end

class FluidGrid
  attr_accessor :grid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size) { FluidCell.new(0.0) } }
  end

  def get_neighbors(x, y)
    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = x + dx, y + dy
      neighbors << @grid[nx][ny] if nx.between?(0, @grid.size - 1) && ny.between?(0, @grid.size - 1)
    end
    neighbors
  end

  def update_cells
    new_grid = Array.new(@grid.size) { Array.new(@grid.size) { FluidCell.new(0.0) } }
    @grid.each_with_index do |row, x|
      row.each_with_index do |cell, y|
        neighbors = get_neighbors(x, y)
        new_grid[x][y].update(neighbors)
      end
    end
    @grid = new_grid
  end
end

def main
  size = 100
  fluid_grid = FluidGrid.new(size)
  fluid_grid.grid[0].each { |cell| cell.value = 1.0 }
  loop do
    fluid_grid.update_cells
  end
end

main