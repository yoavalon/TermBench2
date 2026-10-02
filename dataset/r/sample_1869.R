reward_decay <- function(initial_reward, decay_rate, steps) {
    rewards <- c()
    current_reward <- initial_reward
    for (step in 1:steps) {
        rewards <- c(rewards, current_reward)
        current_reward <- current_reward * decay_rate
    }
    return(rewards)
}

if (sys.nframe() == 0) {
    reward_decay(1.0, 0.95, 10)
}