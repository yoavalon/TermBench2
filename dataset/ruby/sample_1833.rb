def reward_decay
  require 'nmatrix'
  x = 1.0
  decay_rate = 0.99
  epsilon = 1e-06
  while x > epsilon
    x *= decay_rate
  end
  x
end

if __FILE__ == $0
  result = reward_decay
  puts result
end