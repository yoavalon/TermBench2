class Cell
  def initialize(state=0)
    @state = state
  end

  def update(neighbors)
    live_neighbors = neighbors.count { |cell| cell.state == 1 }
    if @state == 1
      @state = live_neighbors.in?([2, 3]) ? 1 : 0
    else
      @state = live_neighbors == 3 ? 1 : 0
    end
  end
end

class Grid
  def initialize(width, height, initial_state=nil)
    @width = width
    @height = height
    @grid = Array.new(height) { Array.new(width) { Cell.new(initial_state ? initial_state[_2][_1] : nil) } }
  end

  def get_neighbors(x, y)
    directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = x + dx, y + dy
      neighbors << @grid[ny][nx] if nx.between?(0, @width - 1) && ny.between?(0, @height - 1)
    end
    neighbors
  end

  def update
    new_grid = Array.new(@height) { Array.new(@width) { Cell.new(@grid[_2][_1].state) } }
    (0...@height).each do |i|
      (0...@width).each do |j|
        neighbors = get_neighbors(j, i)
        new_grid[i][j].update(neighbors)
      end
    end
    @grid = new_grid
  end
end

def main
  initial_state = [[0, 1, 0], [0, 1, 0], [0, 1, 0]]
  grid = Grid.new(3, 3, initial_state)
  loop do
    grid.update
  end
end

main