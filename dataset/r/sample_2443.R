reward_decay <- function(epochs, decay_rate) {
    rewards <- c()
    current_reward <- 1.0
    for (i in 1:epochs) {
        rewards <- c(rewards, current_reward)
        current_reward <- current_reward * decay_rate
    }
    return(rewards)
}

if (R.version.string != "") {
    print(reward_decay(10, 0.9))
}