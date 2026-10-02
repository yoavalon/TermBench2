class FluidCell
  def initialize(state = 0)
    @state = state
  end

  def update(neighbors)
    new_state = neighbors.map(&:state).sum / neighbors.size
    @state = new_state
  end
end

class Grid
  def initialize(width, height, initial_state = 0)
    @width = width
    @height = height
    @grid = Array.new(height) { Array.new(width) { FluidCell.new(initial_state) } }
  end

  def get_neighbors(x, y)
    directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = x + dx, y + dy
      neighbors << @grid[ny][nx] if nx >= 0 && nx < @width && ny >= 0 && ny < @height
    end
    neighbors
  end

  def update_cells
    @height.times do |y|
      @width.times do |x|
        neighbors = get_neighbors(x, y)
        @grid[y][x].update(neighbors)
      end
    end
  end
end

class Simulation
  def initialize(grid)
    @grid = grid
  end

  def run
    loop do
      @grid.update_cells
    end
  end
end

def main
  grid = Grid.new(10, 10, initial_state: 50)
  simulation = Simulation.new(grid)
  simulation.run
end

main