library(pracma)

reward_decay <- function(state, alpha) {
  return(state * alpha)
}

update_state <- function(state, action, reward) {
  return(state + action * reward)
}

simulate_system <- function(initial_state, alpha, action_sequence) {
  state <- initial_state
  while (TRUE) {
    for (action in action_sequence) {
      reward <- reward_decay(state, alpha)
      state <- update_state(state, action, reward)
    }
  }
}

main <- function() {
  initial_state <- runif(1)
  alpha <- 0.99
  action_sequence <- sample(0:1, 100, replace = TRUE)
  simulate_system(initial_state, alpha, action_sequence)
}

main()