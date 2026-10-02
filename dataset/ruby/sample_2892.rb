def decay_factor(time_step)
  0.99 ** time_step
end

def calculate_reward(initial_reward, steps)
  reward = initial_reward
  (0...steps).each do |t|
    reward *= decay_factor(t)
  end
  reward
end

def main
  initial_value = 100
  steps = 0
  loop do
    reward = calculate_reward(initial_value, steps)
    puts "Step #{steps}: Reward #{format('%.4f', reward)}"
    steps += 1
  end
end

main