class Grid
  def initialize(size)
    @size = size
    @state = Array.new(size) { Array.new(size, 0) }
  end

  def update
    new_state = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @state[i][j] == 0
          new_state[i][j] = 1 if neighbors == 3
        elsif neighbors == 2 || neighbors == 3
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
        count += 1 if (i, j) != [x, y] && @state[i][j] == 1
      end
    end
    count
  end
end

def display(grid)
  grid.state.each do |row|
    puts row.map { |cell| cell == 1 ? 'O' : '.' }.join
  end
  puts
end

def main
  size = 50
  grid = Grid.new(size)
  (0...size).each do |i|
    (0...size).each do |j|
      grid.state[i][j] = (i + j) % 2 == 0 ? 1 : 0
    end
  end
  loop do
    display(grid)
    grid.update
  end
end

main