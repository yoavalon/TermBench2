optimize <- function() {
  library(stats)
  
  n <- 10
  d <- 3
  p <- 0.1
  particles <- replicate(n, runif(d))
  
  for (t in 1:100) {
    velocities <- replicate(n, runif(d))
    for (i in 1:n) {
      for (j in 1:d) {
        particles[i, j] <- particles[i, j] + velocities[i, j] * p
      }
    }
  }
  return(particles)
}

optimize()