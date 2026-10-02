library(pracma)

initialize_environment <- function() {
  state <- sample(0:9, 1)
  return(state)
}

update_state <- function(state, action) {
  return((state + action) %% 10)
}

calculate_reward <- function(state) {
  return(sin(state))
}

decay_reward <- function(reward, step) {
  return(reward * 0.9^step)
}

main <- function() {
  state <- initialize_environment()
  step <- 0
  while (TRUE) {
    action <- sample(0:2, 1)
    state <- update_state(state, action)
    reward <- calculate_reward(state)
    reward <- decay_reward(reward, step)
    step <- step + 1
  }
}

main()