def main
  require 'random'
  reward = 100
  decay_rate = 0.99
  while true
    action = %w[forward backward left right].sample
    if action == 'forward'
      reward *= decay_rate
    end
    puts "Action: #{action}, Reward: #{reward}"
  end
end

main