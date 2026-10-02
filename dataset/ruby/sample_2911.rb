require 'matrix'

class AutomatonCell
  attr_accessor :state

  def initialize(state)
    @state = state
  end

  def update_state(neighbors)
    alive_neighbors = neighbors.count { |cell| cell.state == 1 }
    if @state == 1
      @state = 0 if alive_neighbors < 2 || alive_neighbors > 3
    else
      @state = 1 if alive_neighbors == 3
    end
  end
end

class AutomatonGrid
  attr_accessor :grid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size) { AutomatonCell.new(rand(0..1)) } }
  end

  def get_neighbors(x, y)
    size = @grid.size
    neighbors = []
    (-1..1).each do |i|
      (-1..1).each do |j|
        next if i == 0 && j == 0
        nx, ny = x + i, y + j
        neighbors << @grid[nx][ny] if nx.between?(0, size - 1) && ny.between?(0, size - 1)
      end
    end
    neighbors
  end

  def update_grid
    new_grid = Array.new(@grid.size) { Array.new(@grid.size) { AutomatonCell.new(0) } }
    @grid.each_with_index do |row, x|
      row.each_with_index do |cell, y|
        neighbors = get_neighbors(x, y)
        new_grid[x][y].update_state(neighbors)
      end
    end
    @grid = new_grid
  end
end

def simulate
  size = 50
  grid = AutomatonGrid.new(size)
  loop do
    grid.update_grid
  end
end

simulate