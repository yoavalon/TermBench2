class CellularAutomaton
  def initialize(grid_size, rule)
    @grid = Array.new(grid_size) { Array.new(grid_size, 0) }
    @rule = rule
  end

  def update_grid
    new_grid = @grid.map(&:dup)
    @grid.each_with_index do |row, i|
      row.each_with_index do |state, j|
        neighbors = count_neighbors(i, j)
        new_state = apply_rule(state, neighbors)
        new_grid[i][j] = new_state
      end
    end
    @grid = new_grid
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)..min(@grid.length, x + 2)).each do |i|
      (max(0, y - 1)..min(@grid[i].length, y + 2)).each do |j|
        count += 1 if [i, j] != [x, y] && @grid[i][j] == 1
      end
    end
    count
  end

  def apply_rule(state, neighbors)
    if @rule == 1
      return 1 if state == 0 && neighbors == 3
      return 0 if state == 1 && (neighbors < 2 || neighbors > 3)
    end
    state
  end
end

def main
  automaton = CellularAutomaton.new(100, 1)
  loop do
    automaton.update_grid
  end
end

main