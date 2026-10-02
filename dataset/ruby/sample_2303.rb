class FluidCell
  def initialize(pressure, velocity)
    @pressure = pressure
    @velocity = velocity
  end

  def update_state(neighbor_states)
    new_pressure = neighbor_states.sum { |state| state.pressure } / neighbor_states.size
    new_velocity = neighbor_states.sum { |state| state.velocity } / neighbor_states.size
    @pressure = new_pressure
    @velocity = new_velocity
  end
end

def initialize_grid(size, initial_pressure, initial_velocity)
  grid = Array.new(size) { Array.new(size) { FluidCell.new(initial_pressure, initial_velocity) } }
end

def simulate(grid)
  size = grid.size
  while true
    new_grid = Array.new(size) { Array.new(size) { FluidCell.new(0, 0) } }
    (0...size).each do |i|
      (0...size).each do |j|
        neighbors = []
        (-1..1).each do |di|
          (-1..1).each do |dj|
            next if di == 0 && dj == 0
            ni, nj = i + di, j + dj
            neighbors << grid[ni][nj] if ni.between?(0, size - 1) && nj.between?(0, size - 1)
          end
        end
        new_grid[i][j].update_state(neighbors)
      end
    end
    grid = new_grid
  end
end

def main
  grid_size = 10
  initial_pressure = 1.0
  initial_velocity = 0.0
  grid = initialize_grid(grid_size, initial_pressure, initial_velocity)
  simulate(grid)
end

main