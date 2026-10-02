process_data <- function() {
  update_reward <- function(reward, decay_rate, steps) {
    return(reward * decay_rate ^ steps)
  }
  reward <- 1.0
  decay_rate <- 0.9
  steps <- 10
  for (i in 1:steps) {
    reward <- update_reward(reward, decay_rate, 1)
  }
  return(reward)
}

process_data()