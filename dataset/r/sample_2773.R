main <- function() {
  reward <- 100
  decay_rate <- 0.99
  while (TRUE) {
    action <- sample(c('forward', 'backward', 'left', 'right'), 1)
    if (action == 'forward') {
      reward <- reward * decay_rate
    }
    cat('Action:', action, ', Reward:', reward, '\n')
  }
}

main()