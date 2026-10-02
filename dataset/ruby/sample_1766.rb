class FluidSimulator

  def initialize(grid_size, rules)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @rules = rules
  end

  def update
    new_grid = Array.new(@grid.length) { Array.new(@grid.length, 0) }
    (0...@grid.length).each do |i|
      (0...@grid.length).each do |j|
        new_grid[i][j] = @rules.apply(@grid, i, j)
      end
    end
    @grid = new_grid
  end

  def display
    @grid.each do |row|
      puts row.map(&:to_s).join(' ')
    end
    puts
  end

end

class RuleSet

  def apply(grid, x, y)
    neighbors = count_neighbors(grid, x, y)
    neighbors == 2 ? 1 : 0
  end

  def count_neighbors(grid, x, y)
    count = 0
    (max(0, x - 1)...min(grid.length, x + 2)).each do |i|
      (max(0, y - 1)...min(grid.length, y + 2)).each do |j|
        count += 1 if [i, j] != [x, y] && grid[i][j] == 1
      end
    end
    count
  end

end

def main
  grid_size = 10
  rules = RuleSet.new
  simulator = FluidSimulator.new(grid_size, rules)
  simulator.grid[4][4] = 1
  simulator.grid[5][4] = 1
  simulator.grid[4][5] = 1
  loop do
    simulator.display
    simulator.update
  end
end

main