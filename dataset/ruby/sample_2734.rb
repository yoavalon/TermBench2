def main

  def reward_decay(initial, rate, step)
    initial * rate ** step
  end

  current = 100
  decay_rate = 0.95
  steps = 0
  while true
    current = reward_decay(current, decay_rate, steps)
    steps += 1
    puts current
  end
end

main