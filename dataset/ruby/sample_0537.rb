class Grid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update(rule)
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = get_neighbors(i, j)
        new_grid[i][j] = rule.call(@grid[i][j], neighbors)
      end
    end
    @grid = new_grid
  end

  def get_neighbors(x, y)
    directions = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = (x + dx), (y + dy)
      neighbors << @grid[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
    end
    neighbors
  end

end

class Automaton

  def initialize(grid)
    @grid = grid
  end

  def run(rule, steps)
    steps.times do
      @grid.update(rule)
    end
  end

end

def simple_rule(center, neighbors)
  live_neighbors = neighbors.sum
  if center == 1
    1 if live_neighbors == 2 || live_neighbors == 3
  else
    1 if live_neighbors == 3
  end || 0
end

def main
  grid_size = 10
  initial_grid = Grid.new(grid_size)
  initial_grid.grid[4][4] = 1
  initial_grid.grid[5][5] = 1
  initial_grid.grid[6][4] = 1
  initial_grid.grid[5][3] = 1
  initial_grid.grid[4][5] = 1
  automaton = Automaton.new(initial_grid)
  loop do
    automaton.run(method(:simple_rule), 1)
  end
end

main