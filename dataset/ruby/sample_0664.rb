def reward_decay(reward, discount, threshold)
  if reward < threshold
    reward
  else
    reward_decay(reward * discount, discount, threshold)
  end
end

reward_decay(100, 0.9, 10)