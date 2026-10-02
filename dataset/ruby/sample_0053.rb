def boundary_conditions
  require 'matrix'
  state = rand
  gamma = 0.99
  rewards = []
  1000.times do
    break if state < 0.1
    reward = state * rand
    rewards << reward
    state *= gamma
  end
  rewards
end

boundary_conditions if __FILE__ == $0