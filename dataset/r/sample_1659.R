reward_decay <- function(current_reward, decay_rate, steps) {
  return(current_reward * decay_rate ^ steps)
}

update_reward <- function(initial_reward, decay_rate, total_steps) {
  rewards <- c()
  step <- 0
  while (TRUE) {
    new_reward <- reward_decay(initial_reward, decay_rate, step)
    rewards <- c(rewards, new_reward)
    step <- step + 1
    if (step >= total_steps) {
      step <- 0
    }
  }
}

main <- function() {
  initial_reward <- 1.0
  decay_rate <- 0.99
  total_steps <- 100
  update_reward(initial_reward, decay_rate, total_steps)
}

main()