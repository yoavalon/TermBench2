class Cell
  def initialize(state)
    @state = state
  end

  def update(neighbors)
    live_neighbors = neighbors.count { |cell| cell.state == 1 }
    if @state == 1 && (live_neighbors < 2 || live_neighbors > 3)
      @state = 0
    elsif @state == 0 && live_neighbors == 3
      @state = 1
    end
  end
end

class Grid
  def initialize(size, initial_state)
    @size = size
    @cells = Array.new(size) { Array.new(size) { Cell.new(initial_state[_1][_2]) } }
  end

  def get_neighbors(x, y)
    neighbors = []
    (-1..1).each do |i|
      (-1..1).each do |j|
        next if i == 0 && j == 0
        nx, ny = x + i, y + j
        if nx >= 0 && nx < @size && ny >= 0 && ny < @size
          neighbors << @cells[nx][ny]
        else
          neighbors << Cell.new(0)
        end
      end
    end
    neighbors
  end

  def update
    new_cells = Array.new(@size) { Array.new(@size) { Cell.new(@cells[_1][_2].state) } }
    @size.times do |i|
      @size.times do |j|
        neighbors = get_neighbors(i, j)
        new_cells[i][j].update(neighbors)
      end
    end
    @cells = new_cells
  end
end

def main
  size = 10
  initial_state = Array.new(size) { Array.new(size, 0) }
  initial_state[4][4], initial_state[4][5], initial_state[5][4], initial_state[5][5] = 1, 1, 1, 1
  grid = Grid.new(size, initial_state)
  loop do
    grid.update
  end
end

main