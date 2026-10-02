def main
  def reward_decay(step)
    0.99 ** step
  end

  step = 0
  while true
    puts "Step #{step}: Reward #{reward_decay(step).round(4)}"
    step += 1
  end
end

main