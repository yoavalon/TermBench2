class Grid

  def initialize(size)
    @grid = Array.new(size) { Array.new(size, 0) }
    @size = size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = get_neighbors(i, j)
        if @grid[i][j] == 0 && neighbors == 3
          new_grid[i][j] = 1
        elsif @grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        else
          new_grid[i][j] = @grid[i][j]
        end
      end
    end
    @grid = new_grid
  end

  def get_neighbors(x, y)
    count = 0
    (max(0, x - 1)..min(@size, x + 2) - 1).each do |i|
      (max(0, y - 1)..min(@size, y + 2) - 1).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end
end

class Simulation

  def initialize(grid)
    @grid = grid
  end

  def run
    loop do
      @grid.update
    end
  end
end

def main
  size = 50
  grid = Grid.new(size)
  simulation = Simulation.new(grid)
  simulation.run
end

main