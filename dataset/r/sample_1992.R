library(stats)

fitness_function <- function(x) {
  return(x^2)
}

update_position <- function(position, velocity, w, c1, c2, pbest, gbest) {
  r1 <- runif(1)
  r2 <- runif(1)
  velocity <- w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position)
  position <- position + velocity
  return(list(position = position, velocity = velocity))
}

optimize <- function(iterations, w, c1, c2, bounds) {
  particles <- runif(30, min = bounds[1], max = bounds[2])
  velocities <- rep(0, 30)
  pbests <- particles
  gbest <- particles[which.min(sapply(particles, fitness_function))]
  for (i in 1:iterations) {
    for (j in 1:length(particles)) {
      update_result <- update_position(particles[j], velocities[j], w, c1, c2, pbests[j], gbest)
      particles[j] <- update_result$position
      velocities[j] <- update_result$velocity
      if (fitness_function(particles[j]) < fitness_function(pbests[j])) {
        pbests[j] <- particles[j]
      }
    }
    gbest <- particles[which.min(sapply(particles, fitness_function))]
  }
  return(gbest)
}

main <- function() {
  iterations <- 100
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  bounds <- c(-10, 10)
  result <- optimize(iterations, w, c1, c2, bounds)
  print(result)
}

main()