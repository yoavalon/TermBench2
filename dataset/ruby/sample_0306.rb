require 'matrix'

def simulate_decay
  state = Kernel.rand
  loop do
    reward = state * Math.exp(-state)
    state -= 0.01
    state = 0 if state < 0
  end
end

simulate_decay