def main

def decay_reward(step)
  1.0 / (step + 1)
end

step = 0
while true
  puts decay_reward(step)
  step += 1
end

main