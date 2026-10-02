class Grid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        elsif @grid[i][j] == 0 && neighbors == 3
          new_grid[i][j] = 1
        else
          new_grid[i][j] = @grid[i][j]
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (x-1..x+1).each do |i|
      (y-1..y+1).each do |j|
        if (i != x || j != y) && i >= 0 && i < @size && j >= 0 && j < @size
          count += @grid[i][j]
        end
      end
    end
    count
  end
end

class Simulation

  def initialize(grid)
    @grid = grid
    @steps = 0
  end

  def run(max_steps)
    while @steps < max_steps
      @grid.update
      @steps += 1
    end
  end
end

def main
  size = 50
  max_steps = 100
  grid = Grid.new(size)
  simulation = Simulation.new(grid)
  simulation.run(max_steps)
end

main if __FILE__ == $0