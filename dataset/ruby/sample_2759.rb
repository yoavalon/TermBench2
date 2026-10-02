require 'matrix'

def simulate
  def update(state)
    neighbors = state.each_with_index.map do |cell, i, j|
      [
        state[i, (j + 1) % state.column_count],
        state[i, (j - 1) % state.column_count],
        state[(i + 1) % state.row_count, j],
        state[(i - 1) % state.row_count, j]
      ].sum
    end

    state.map_with_index do |cell, i, j|
      if cell == 1 && neighbors[i][j] < 2
        0
      elsif cell == 1 && neighbors[i][j] > 3
        0
      elsif cell == 0 && neighbors[i][j] == 3
        1
      else
        cell
      end
    end
  end

  size = [20, 20]
  state = Matrix.build(*size) { rand(2) }

  loop do
    state = update(state)
  end
end

simulate