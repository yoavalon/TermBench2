main <- function() {
  reward <- 1.0
  decay_rate <- 0.99
  step <- 0
  while (TRUE) {
    cat(paste("Step", step, ": Reward", reward, "\n"))
    reward <- reward * decay_rate
    step <- step + 1
  }
}

main()