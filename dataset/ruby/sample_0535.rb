class Cell
  def initialize(state)
    @state = state
  end

  def update(neighbors)
    alive_neighbors = neighbors.count { |n| n.state == 1 }
    if @state == 1
      if alive_neighbors < 2 || alive_neighbors > 3
        @state = 0
      end
    elsif alive_neighbors == 3
      @state = 1
    end
  end
end

class Grid
  def initialize(width, height, initial_state)
    @width = width
    @height = height
    @grid = Array.new(width) { Array.new(height) { Cell.new(initial_state[_1][_2]) } }
  end

  def get_neighbors(x, y)
    neighbors = []
    (-1..1).each do |dx|
      (-1..1).each do |dy|
        next if dx == 0 && dy == 0
        nx, ny = x + dx, y + dy
        neighbors << @grid[nx][ny] if nx >= 0 && nx < @width && ny >= 0 && ny < @height
      end
    end
    neighbors
  end

  def update
    new_grid = Array.new(@width) { Array.new(@height) { Cell.new(0) } }
    (0...@width).each do |x|
      (0...@height).each do |y|
        cell = @grid[x][y]
        neighbors = get_neighbors(x, y)
        new_grid[x][y].update(neighbors)
      end
    end
    @grid = new_grid
  end
end

def main
  width, height = 10, 10
  initial_state = [
    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
  ]
  grid = Grid.new(width, height, initial_state)
  loop do
    grid.update
  end
end

main