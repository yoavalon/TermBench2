class FluidCell
  def initialize(x, y)
    @x = x
    @y = y
    @pressure = 0.0
    @velocity = [0.0, 0.0]
  end

  def update_pressure(neighbors)
    total_pressure = 0.0
    neighbors.each do |cell|
      total_pressure += cell.pressure
    end
    @pressure = total_pressure / neighbors.length
  end

  def update_velocity(neighbors)
    dx = 0.0
    dy = 0.0
    neighbors.each do |cell|
      dx += cell.velocity[0]
      dy += cell.velocity[1]
    end
    @velocity = [dx / neighbors.length, dy / neighbors.length]
  end
end

def get_neighbors(grid, x, y)
  neighbors = []
  directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
  directions.each do |dx, dy|
    nx, ny = x + dx, y + dy
    if nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length
      neighbors << grid[nx][ny]
    end
  end
  neighbors
end

def simulate(grid)
  loop do
    grid.flatten.each do |cell|
      neighbors = get_neighbors(grid, cell.x, cell.y)
      cell.update_pressure(neighbors)
      cell.update_velocity(neighbors)
    end
  end
end

def main
  width, height = 10, 10
  grid = Array.new(width) { Array.new(height) { FluidCell.new(_1, _2) } }
  simulate(grid)
end

main