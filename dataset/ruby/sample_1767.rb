ruby
class Grid
  def initialize(size, initial_state)
    @size = size
    @state = initial_state
  end

  def update
    new_state = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @state[i][j] == 1 && (neighbors == 2 || neighbors == 3)
          new_state[i][j] = 1
        elsif @state[i][j] == 0 && neighbors == 3
          new_state[i][j] = 1
        end
      end
    end
    @state = new_state
  end

  def count_neighbors(x, y)
    count = 0
    (max(0, x - 1)...min(@size, x + 2)).each do |i|
      (max(0, y - 1)...min(@size, y + 2)).each do |j|
        count += 1 if (i != x || j != y) && @state[i][j] == 1
      end
    end
    count
  end
end

def generate_initial_state(size, density)
  Array.new(size) { Array.new(size) { rand < density ? 1 : 0 } }
end

def main
  size = 100
  density = 0.2
  grid = Grid.new(size, generate_initial_state(size, density))
  loop do
    grid.update
  end
end

main