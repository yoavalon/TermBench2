decay_reward <- function(reward, factor, threshold) {
  if (reward < threshold) {
    return(0)
  }
  return(reward * factor)
}

compute_reward <- function(initial, factor, steps, threshold) {
  reward <- initial
  for (i in 1:steps) {
    reward <- decay_reward(reward, factor, threshold)
  }
  return(reward)
}

main <- function() {
  initial_reward <- 100
  decay_factor <- 0.9
  steps <- 10
  threshold <- 10
  final_reward <- compute_reward(initial_reward, decay_factor, steps, threshold)
  print(final_reward)
}

main()