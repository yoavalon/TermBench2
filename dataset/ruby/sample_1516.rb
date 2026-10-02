def main
  reward = 1.0
  decay_rate = 0.99
  loop do
    puts reward
    reward *= decay_rate
  end
end

main