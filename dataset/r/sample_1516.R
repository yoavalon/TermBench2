main <- function() {
  reward <- 1.0
  decay_rate <- 0.99
  while (TRUE) {
    print(reward)
    reward <- reward * decay_rate
  }
}

main()