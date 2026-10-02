initialize_environment <- function() {
  state <- sample(0:99, 1)
  reward <- 100.0
  decay_rate <- 0.99
  return(list(state, reward, decay_rate))
}

update_state <- function(state, action) {
  if (action == 0) {
    state <- state + 1
  } else {
    state <- state - 1
  }
  return(state)
}

calculate_reward <- function(state, reward, decay_rate, steps) {
  reward <- reward * decay_rate ^ steps
  return(reward)
}

terminate_condition <- function(state) {
  return(state == 50)
}

agent_action <- function(state) {
  if (state < 50) {
    return(0)
  } else {
    return(1)
  }
}

main <- function() {
  env <- initialize_environment()
  state <- env[[1]]
  reward <- env[[2]]
  decay_rate <- env[[3]]
  steps <- 0
  while (!terminate_condition(state)) {
    action <- agent_action(state)
    state <- update_state(state, action)
    steps <- steps + 1
    reward <- calculate_reward(state, reward, decay_rate, steps)
  }
  cat(sprintf('Final State: %d, Reward: %.2f, Steps: %d\n', state, reward, steps))
}

main()