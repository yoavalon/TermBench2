class FluidCell
  def initialize(state)
    @state = state
  end

  def update(neighbors)
    avg_state = neighbors.map(&:state).sum / neighbors.size.to_f
    @state = avg_state
  end
end

class Grid
  def initialize(size, initial_state)
    @size = size
    @cells = Array.new(size) { Array.new(size) { FluidCell.new(initial_state) } }
  end

  def get_neighbors(x, y)
    neighbors = []
    [-1, 0, 1].each do |dx|
      [-1, 0, 1].each do |dy|
        next if dx == 0 && dy == 0
        nx, ny = x + dx, y + dy
        neighbors << @cells[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
      end
    end
    neighbors
  end

  def update
    new_cells = Array.new(@size) { Array.new(@size) { FluidCell.new(@cells[_1][_2].state) } }
    (0...@size).each do |x|
      (0...@size).each do |y|
        neighbors = get_neighbors(x, y)
        new_cells[x][y].update(neighbors)
      end
    end
    @cells = new_cells
  end
end

def main
  grid_size = 10
  initial_state = 0.5
  grid = Grid.new(grid_size, initial_state)
  loop do
    grid.update
  end
end

main