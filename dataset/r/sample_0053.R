boundary_conditions <- function() {
  state <- runif(1)
  gamma <- 0.99
  rewards <- c()
  for (i in 1:1000) {
    if (state < 0.1) {
      break
    }
    reward <- state * runif(1)
    rewards <- c(rewards, reward)
    state <- state * gamma
  }
  return(rewards)
}

if (sys.nframe() == 0) {
  boundary_conditions()
}