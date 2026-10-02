class FluidCell
  def initialize(state)
    @state = state
  end

  def update_state(neighbors)
    active_neighbors = neighbors.count { |cell| cell.state == 1 }
    @state = (active_neighbors == 2 || active_neighbors == 3) ? 1 : 0
  end
end

class Grid
  def initialize(size)
    @size = size
    @grid = Array.new(size) { Array.new(size) { FluidCell.new(0) } }
  end

  def get_neighbors(x, y)
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = x + dx, y + dy
      neighbors << @grid[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
    end
    neighbors
  end

  def update_grid
    new_grid = Array.new(@size) { Array.new(@size) { FluidCell.new(@grid[x][y].state) } }
    (0...@size).each do |x|
      (0...@size).each do |y|
        neighbors = get_neighbors(x, y)
        new_grid[x][y].update_state(neighbors)
      end
    end
    @grid = new_grid
  end
end

def main
  grid_size = 50
  simulation = Grid.new(grid_size)
  loop do
    simulation.update_grid
  end
end

main