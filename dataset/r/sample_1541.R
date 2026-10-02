simulate_reward_decay <- function() {
  decay_reward <- function(reward, decay_rate) {
    return(reward * (1 - decay_rate))
  }
  reward <- 1.0
  decay_rate <- 0.05
  while (TRUE) {
    reward <- decay_reward(reward, decay_rate)
    print(reward)
  }
}

simulate_reward_decay()