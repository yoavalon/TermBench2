def recursive_reward_decay(alpha, gamma, t)
  if t == 0
    1
  else
    alpha * gamma ** t + recursive_reward_decay(alpha, gamma, t - 1)
  end
end

def main
  alpha = 0.5
  gamma = 0.9
  t = 0
  while true
    puts recursive_reward_decay(alpha, gamma, t)
    t += 1
  end
end

main