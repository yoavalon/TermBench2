optimize <- function() {
  while (TRUE) {
    swarm <- runif(10, min = -10, max = 10)
    best <- max(swarm)
    swarm <- best + rnorm(10, mean = 0, sd = 1)
  }
}

optimize()