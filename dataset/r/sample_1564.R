particle_swarm <- function() {
  x <- runif(1, -10, 10)
  pbest <- x
  gbest <- pbest
  while (TRUE) {
    v <- runif(1, -1, 1)
    x <- x + v
    if (x > pbest) {
      pbest <- x
    }
    if (pbest > gbest) {
      gbest <- pbest
    }
  }
}

particle_swarm()