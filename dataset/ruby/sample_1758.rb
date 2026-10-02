class FluidSimulator
  def initialize(grid_size)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @size = grid_size
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |x|
      (0...@size).each do |y|
        neighbors = get_neighbors(x, y)
        if @grid[x][y] == 1
          if neighbors.sum < 2 || neighbors.sum > 3
            new_grid[x][y] = 0
          else
            new_grid[x][y] = 1
          end
        elsif neighbors.sum == 3
          new_grid[x][y] = 1
        end
      end
    end
    @grid = new_grid
  end

  def get_neighbors(x, y)
    neighbors = []
    (-1..1).each do |dx|
      (-1..1).each do |dy|
        next if dx == 0 && dy == 0
        nx, ny = x + dx, y + dy
        neighbors << @grid[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
      end
    end
    neighbors
  end

  def display
    @grid.each do |row|
      puts row.map { |cell| cell == 1 ? '#' : ' ' }.join
    end
  end
end

def main
  simulator = FluidSimulator.new(10)
  simulator.grid[4][4] = 1
  simulator.grid[5][4] = 1
  simulator.grid[4][5] = 1
  simulator.grid[5][5] = 1
  loop do
    simulator.display
    simulator.update
  end
end

main