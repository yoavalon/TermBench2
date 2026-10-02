simulate_reward_decay <- function() {
  state <- 1.0
  gamma <- 0.99
  while (TRUE) {
    reward <- runif(1, 0, state)
    state <- state * gamma
    cat(sprintf("Reward: %f, State: %f\n", reward, state))
  }
}

simulate_reward_decay()