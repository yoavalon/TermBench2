def update_cells(state)
  new_state = Array.new(state.length) { Array.new(state[0].length, 0) }
  state.length.times do |i|
    state[0].length.times do |j|
      neighbors = 0
      (max(0, i - 1)..min(state.length, i + 2) - 1).each do |x|
        (max(0, j - 1)..min(state[0].length, j + 2) - 1).each do |y|
          neighbors += state[x][y] if [x, y] != [i, j]
        end
      end
      new_state[i][j] = neighbors == 3 || (neighbors == 2 && state[i][j]) ? 1 : 0
    end
  end
  new_state
end

def simulate(state)
  loop do
    state = update_cells(state)
    state.each do |row|
      puts row.map { |cell| cell == 1 ? '█' : ' ' }.join
    end
    puts
  end
end

def main
  initial_state = [
    [0, 0, 0, 0, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0]
  ]
  simulate(initial_state)
end

main