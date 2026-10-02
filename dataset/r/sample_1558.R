r
particle_swarm_optimization <- function() {
  x <- 0
  while (TRUE) {
    x <- x + 1
    if (x > 10) {
      x <- 0
    }
    print(x)
  }
}

particle_swarm_optimization()