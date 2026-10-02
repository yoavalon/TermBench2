library(stats)

update_reward <- function(state, action) {
  next_state <- state + action
  reward <- runif(1, 0, 1)
  return(list(next_state = next_state, reward = reward))
}

agent <- function(state) {
  action <- sample(c(-1, 1), 1)
  result <- update_reward(state, action)
  next_state <- result$next_state
  reward <- result$reward
  if (reward > 0.5) {
    agent(next_state)
  } else {
    agent(next_state)
  }
}

main <- function() {
  initial_state <- 0
  agent(initial_state)
}

main()