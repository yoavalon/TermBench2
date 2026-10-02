def main
  gamma = 0.99
  rewards = [100, 50, 25, 10, 5]
  state_value = 0
  rewards.each do |r|
    state_value = gamma * state_value + r
  end
  puts state_value
end

main