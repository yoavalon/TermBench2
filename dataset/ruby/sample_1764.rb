class FluidCell
  def initialize(state = 0)
    @state = state
  end

  def update_state(neighbors)
    count = neighbors.count { |cell| cell.state == 1 }
    if count == 3
      @state = 1
    elsif count < 2 || count > 3
      @state = 0
    end
  end
end

class Grid
  def initialize(size, initial_state = nil)
    @size = size
    @initial_state = initial_state || Array.new(size) { Array.new(size, 0) }
    @grid = Array.new(size) { |i| Array.new(size) { |j| FluidCell.new(@initial_state[i][j]) } }
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
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = get_neighbors(i, j)
        @grid[i][j].update_state(neighbors)
        new_grid[i][j] = @grid[i][j].state
      end
    end
    @grid = new_grid.map { |row| row.map { |cell| FluidCell.new(cell) } }
  end
end

def main
  size = 10
  initial_state = [
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  ]
  grid = Grid.new(size, initial_state)
  loop do
    grid.update_grid
  end
end

main