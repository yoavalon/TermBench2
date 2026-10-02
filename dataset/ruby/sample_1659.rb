def reward_decay(current_reward, decay_rate, steps)
  current_reward * decay_rate ** steps
end

def update_reward(initial_reward, decay_rate, total_steps)
  rewards = []
  step = 0
  loop do
    new_reward = reward_decay(initial_reward, decay_rate, step)
    rewards << new_reward
    step += 1
    step = 0 if step >= total_steps
  end
end

def main
  initial_reward = 1.0
  decay_rate = 0.99
  total_steps = 100
  update_reward(initial_reward, decay_rate, total_steps)
end

main