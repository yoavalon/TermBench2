update_reward <- function(state, action) {
  if (action == 0) {
    return(state * 0.95)
  } else {
    return(state * 0.9)
  }
}

simulate_episodes <- function(num_episodes, max_steps) {
  rewards <- c()
  for (i in 1:num_episodes) {
    state <- 1.0
    for (j in 1:max_steps) {
      action <- sample(0:1, 1)
      state <- update_reward(state, action)
      if (state < 0.1) {
        break
      }
    }
    rewards <- c(rewards, state)
  }
  return(mean(rewards))
}

main <- function() {
  result <- simulate_episodes(100, 1000)
  print(result)
}

main()