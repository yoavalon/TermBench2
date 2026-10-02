class Automaton
  def initialize(size, initial_state)
    @size = size
    @state = initial_state
  end

  def update
    new_state = Array.new(@size) { Array.new(@size, 0) }
    (0...@size).each do |i|
      (0...@size).each do |j|
        neighbors = count_neighbors(i, j)
        if @state[i][j] == 1
          new_state[i][j] = (2 <= neighbors && neighbors <= 3) ? 1 : 0
        else
          new_state[i][j] = (neighbors == 3) ? 1 : 0
        end
      end
    end
    @state = new_state
  end

  def count_neighbors(x, y)
    count = 0
    (x - 1...x + 2).each do |i|
      (y - 1...y + 2).each do |j|
        if (0 <= i && i < @size && 0 <= j && j < @size) && (i != x || j != y)
          count += @state[i][j]
        end
      end
    end
    count
  end
end

def generate_initial_state(size)
  initial_state = Array.new(size) { Array.new(size) { [0, 1].sample } }
end

def main
  size = 10
  initial_state = generate_initial_state(size)
  automaton = Automaton.new(size, initial_state)
  loop do
    automaton.update
  end
end

main