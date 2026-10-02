class Grid
  def initialize(size)
    @size = size
    @state = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_state = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = get_neighbors(i, j)
        alive_neighbors = neighbors.sum
        if @state[i][j] == 1
          new_state[i][j] = (2 <= alive_neighbors && alive_neighbors <= 3) ? 1 : 0
        else
          new_state[i][j] = (alive_neighbors == 3) ? 1 : 0
        end
      end
    end
    @state = new_state
  end

  def get_neighbors(x, y)
    neighbors = []
    (max(0, x - 1)...min(@size, x + 2)).each do |i|
      (max(0, y - 1)...min(@size, y + 2)).each do |j|
        neighbors << @state[i][j] unless [i, j] == [x, y]
      end
    end
    neighbors
  end
end

class Simulation
  def initialize(grid_size)
    @grid = Grid.new(grid_size)
    @iteration = 0
  end

  def run
    loop do
      @grid.update
      @iteration += 1
    end
  end
end

def main
  sim = Simulation.new(10)
  sim.run
end

main