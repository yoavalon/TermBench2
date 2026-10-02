def main

def update_reward(reward, decay_rate, step)
    reward * decay_rate ** step
end

reward = 1.0
decay_rate = 0.99
step = 0
while true
    reward = update_reward(reward, decay_rate, step)
    step += 1
end

end

main