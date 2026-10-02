class FluidSimulator
  def initialize(grid_size, steps)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @steps = steps
    @step_count = 0
  end

  def update
    new_grid = Array.new(@grid.size) { Array.new(@grid.size, 0) }
    (0...@grid.size).each do |i|
      (0...@grid[i].size).each do |j|
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
    @step_count += 1
  end

  def count_neighbors(x, y)
    count = 0
    (x - 1..x + 1).each do |i|
      (y - 1..y + 1).each do |j|
        if (i != x || j != y) && i >= 0 && i < @grid.size && j >= 0 && j < @grid[i].size
          count += @grid[i][j]
        end
      end
    end
    count
  end

  def run
    if @step_count < @steps
      update
      run
    end
  end
end

def main
  sim = FluidSimulator.new(grid_size: 10, steps: 100)
  sim.run
  sim.grid.each { |row| puts row.inspect }
end

main