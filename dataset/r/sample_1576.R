data_mutations <- function() {
  reward_decay <- function(alpha, t) {
    return(alpha ^ t)
  }
  alpha <- 0.99
  t <- 0
  while (TRUE) {
    print(reward_decay(alpha, t))
    t <- t + 1
  }
}

data_mutations()