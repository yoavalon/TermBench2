def decay_reward(base, factor, threshold, value=1)
  if value * factor < threshold
    return value
  else
    decay_reward(base, factor, threshold, value * factor)
  end
end

decay_reward(0.9, 0.95, 0.1)