main <- function() {
  update_reward <- function(reward, decay_rate, step) {
    return(reward * decay_rate ^ step)
  }
  reward <- 1.0
  decay_rate <- 0.99
  step <- 0
  while (TRUE) {
    reward <- update_reward(reward, decay_rate, step)
    step <- step + 1
  }
}

main()