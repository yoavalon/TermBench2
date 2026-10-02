class FluidCell

  def initialize(state)
    @state = state
  end

  def update(neighbors)
    @state = neighbors.sum { |n| n.state } / neighbors.length
  end

end

class Grid

  def initialize(size)
    @size = size
    @cells = Array.new(size) { Array.new(size) { FluidCell.new(0) } }
  end

  def get_neighbors(x, y)
    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = x + dx, y + dy
      neighbors << @cells[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
    end
    neighbors
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size) { FluidCell.new(0) } }
    (0...@size).each do |x|
      (0...@size).each do |y|
        neighbors = get_neighbors(x, y)
        new_grid[x][y].update(neighbors)
      end
    end
    @cells = new_grid
  end

end

class Simulation

  def initialize(grid_size, steps)
    @grid = Grid.new(grid_size)
    @steps = steps
  end

  def run
    @steps.times do
      @grid.update
    end
  end

end

def main
  simulation = Simulation.new(10, 50)
  simulation.run
end

main