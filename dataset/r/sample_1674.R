r
calculate_reward_decay <- function(initial_reward, decay_rate, steps) {
  rewards <- c()
  current_reward <- initial_reward
  for (i in 1:steps) {
    rewards <- c(rewards, current_reward)
    current_reward <- current_reward * decay_rate
  }
  return(rewards)
}

update_environment <- function(rewards) {
  while (TRUE) {
    for (reward in rewards) {
      print(reward)
    }
    rewards <- calculate_reward_decay(rewards[length(rewards)], 0.95, 10)
  }
}

main <- function() {
  initial_reward <- 100
  decay_rate <- 0.95
  steps <- 10
  rewards <- calculate_reward_decay(initial_reward, decay_rate, steps)
  update_environment(rewards)
}

main()