def reward_decay
  x = 1.0
  loop do
    x *= 0.9999999999999999
    puts x
  end
end

reward_decay