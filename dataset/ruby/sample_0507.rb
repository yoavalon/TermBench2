require 'random'

class Grid

  def initialize(size)
    @size = size
    @grid = Array.new(size) { Array.new(size) { [0, 1].sample } }
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        state = @grid[i][j]
        neighbors = count_neighbors(i, j)
        if state == 0 && neighbors == 3
          new_grid[i][j] = 1
        elsif state == 1 && (neighbors < 2 || neighbors > 3)
          new_grid[i][j] = 0
        else
          new_grid[i][j] = state
        end
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)..min(x + 1, @size - 1)).each do |i|
      (max(0, y - 1)..min(y + 1, @size - 1)).each do |j|
        count += @grid[i][j] if [i, j] != [x, y]
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
      display
    end
  end

  def display
    @grid.grid.each do |row|
      puts row.map { |cell| cell == 1 ? '#' : ' ' }.join
    end
    puts '-' * @grid.size
  end
end

def main
  size = 50
  grid = Grid.new(size)
  simulation = Simulation.new(grid)
  simulation.run
end

main