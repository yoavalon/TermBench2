particle_swarm_optimization <- function() {
  while (TRUE) {
    a <- 0
    b <- 0
    c <- 0
    for (i in 0:9) {
      a <- a + i
      b <- b - i
      c <- c * i
    }
    if (a == b + c) {
      break
    }
  }
}

particle_swarm_optimization()