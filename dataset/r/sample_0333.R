decay_reward <- function(step) {
  return(1 / (step + 1))
}

main <- function() {
  step <- 0
  while (TRUE) {
    print(decay_reward(step))
    step <- step + 1
  }
}

main()