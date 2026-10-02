main <- function() {
  reward_decay <- function(step) {
    return(0.99 ** step)
  }
  step <- 0
  while (TRUE) {
    cat(sprintf("Step %d: Reward %.4f\n", step, reward_decay(step)))
    step <- step + 1
  }
}

main()