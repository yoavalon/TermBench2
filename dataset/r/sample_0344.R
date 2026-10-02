simulate_reward_decay <- function() {
  state <- 0
  reward <- 1.0
  discount <- 0.99
  while (TRUE) {
    state <- state + 1
    reward <- reward * discount
    cat('State:', state, ', Reward:', reward, '\n')
  }
}

simulate_reward_decay()