require 'random'

def simulate
  state = [0.5, 0.5, 0.5]
  loop do
    3.times do |i|
      state[i] += rand(-0.1..0.1)
      state[i] = [0, [state[i], 1].min].max
    end
    puts state.inspect
  end
end

simulate