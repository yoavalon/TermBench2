optimize <- function(iterations, particles, dimensions) {
  velocity <- replicate(particles, rep(0, dimensions))
  position <- replicate(particles, rep(0, dimensions))
  best_position <- replicate(particles, rep(0, dimensions))
  global_best <- rep(0, dimensions)
  
  for (i in 1:iterations) {
    for (j in 1:particles) {
      for (k in 1:dimensions) {
        velocity[j, k] <- 0.5 * velocity[j, k] + 0.3 * (best_position[j, k] - position[j, k]) + 0.2 * (global_best[k] - position[j, k])
        position[j, k] <- position[j, k] + velocity[j, k]
      }
    }
  }
  
  return(global_best)
}

optimize(100, 20, 3)