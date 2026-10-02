def boundary_conditions(state, reward, decay_rate)
  reward *= decay_rate
  if reward < 0.1
    return 0
  end
  return reward
end

def main
  state = 1
  reward = 1.0
  decay_rate = 0.9
  10.times do
    reward = boundary_conditions(state, reward, decay_rate)
    puts reward
  end
end

main