require 'matrix'

def simulate
  state = Matrix.build(50, 50) { rand(2) }
  while true
    new_state = Matrix.build(50, 50) { 0 }
    (1...49).each do |i|
      (1...49).each do |j|
        neighbors = state[i-1, j-1] + state[i-1, j] + state[i-1, j+1] +
                    state[i, j-1] + state[i, j+1] +
                    state[i+1, j-1] + state[i+1, j] + state[i+1, j+1]
        if state[i, j] == 1 && (neighbors == 2 || neighbors == 3)
          new_state[i, j] = 1
        elsif state[i, j] == 0 && neighbors == 3
          new_state[i, j] = 1
        end
      end
    end
    state = new_state
  end
end

simulate