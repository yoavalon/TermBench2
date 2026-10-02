update_velocity <- function(particles, velocities, pbest, gbest, w, c1, c2) {
  for (i in 1:nrow(particles)) {
    for (j in 1:ncol(particles)) {
      r1 <- runif(1)
      r2 <- runif(1)
      velocities[i, j] <- w * velocities[i, j] + c1 * r1 * (pbest[i, j] - particles[i, j]) + c2 * r2 * (gbest[j] - particles[i, j])
    }
  }
}

update_position <- function(particles, velocities) {
  for (i in 1:nrow(particles)) {
    for (j in 1:ncol(particles)) {
      particles[i, j] <- particles[i, j] + velocities[i, j]
    }
  }
}

optimize <- function(particles, velocities, pbest, gbest, w, c1, c2) {
  update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
  update_position(particles, velocities)
  optimize(particles, velocities, pbest, gbest, w, c1, c2)
}

main <- function() {
  num_particles <- 10
  dimensions <- 2
  particles <- matrix(runif(num_particles * dimensions, min = -10, max = 10), nrow = num_particles)
  velocities <- matrix(runif(num_particles * dimensions, min = -1, max = 1), nrow = num_particles)
  pbest <- particles
  gbest <- particles[which.min(apply(particles, 1, fitness)), , drop = FALSE]
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  optimize(particles, velocities, pbest, gbest, w, c1, c2)
}

fitness <- function(position) {
  return(sum(position^2))
}

main()