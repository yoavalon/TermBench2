def data_mutations

  def reward_decay(alpha, t)
    alpha ** t
  end

  alpha = 0.99
  t = 0
  while true
    puts reward_decay(alpha, t)
    t += 1
  end
end

data_mutations