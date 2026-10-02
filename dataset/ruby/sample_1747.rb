class FluidSimulator
  def initialize(size, initial_state)
    @size = size
    @state = initial_state
  end

  def update_state
    new_state = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = get_neighbors(i, j)
        new_state[i][j] = apply_rules(neighbors)
      end
    end
    @state = new_state
  end

  def get_neighbors(x, y)
    directions = [[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]]
    neighbors = []
    directions.each do |dx, dy|
      nx, ny = (x + dx), (y + dy)
      neighbors << @state[nx][ny] if nx.between?(0, @size - 1) && ny.between?(0, @size - 1)
    end
    neighbors
  end

  def apply_rules(neighbors)
    active_neighbors = neighbors.sum
    if @state[0][0] == 1
      active_neighbors >= 2 ? 1 : 0
    else
      active_neighbors == 3 ? 1 : 0
    end
  end
end

def initialize_grid(size)
  Array.new(size) { |i| Array.new(size) { |j| i.even? ^ j.even? ? 1 : 0 } }
end

def main
  grid_size = 10
  initial_state = initialize_grid(grid_size)
  simulator = FluidSimulator.new(grid_size, initial_state)
  loop do
    simulator.update_state
  end
end

main