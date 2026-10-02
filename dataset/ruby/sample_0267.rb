class Grid
  def initialize(size, boundary)
    @size = size
    @grid = Array.new(size) { Array.new(size, 0) }
    @boundary = boundary
  end

  def update
    new_grid = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = boundary_condition(i, j)
        new_grid[i][j] = apply_rules(neighbors, @grid[i][j])
      end
    end
    @grid = new_grid
  end

  def boundary_condition(x, y)
    neighbors = []
    [-1, 0, 1].each do |dx|
      [-1, 0, 1].each do |dy|
        next if dx == 0 && dy == 0
        nx, ny = x + dx, y + dy
        if @boundary == 'fixed'
          neighbors << @grid[nx][ny] if nx >= 0 && nx < @size && ny >= 0 && ny < @size
        elsif @boundary == 'periodic'
          neighbors << @grid[(nx + @size) % @size][(ny + @size) % @size]
        end
      end
    end
    neighbors
  end

  def apply_rules(neighbors, current)
    count = neighbors.sum
    if current == 1
      return 0 if count < 2 || count > 3
      1
    else
      return 1 if count == 3
      0
    end
  end
end

def main
  size = 10
  boundary = 'periodic'
  grid = Grid.new(size, boundary)
  steps = 50
  steps.times { grid.update }
end

main if __FILE__ == $0