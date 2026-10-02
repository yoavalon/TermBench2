library(stats)

update_velocity <- function(p, g, v, w, c1, c2) {
  r1 <- runif(1)
  r2 <- runif(1)
  return(w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p))
}

update_position <- function(p, v) {
  return(p + v)
}

optimize <- function(particles, velocities, best_positions, global_best, w, c1, c2) {
  new_particles <- c()
  new_velocities <- c()
  new_best_positions <- c()
  for (i in 1:length(particles)) {
    v <- update_velocity(particles[i], global_best, velocities[i], w, c1, c2)
    p <- update_position(particles[i], v)
    new_particles <- c(new_particles, p)
    new_velocities <- c(new_velocities, v)
    if (p < best_positions[i]) {
      new_best_positions <- c(new_best_positions, p)
    } else {
      new_best_positions <- c(new_best_positions, best_positions[i])
    }
  }
  return(list(new_particles, new_velocities, new_best_positions))
}

swarm <- function() {
  particles <- runif(10)
  velocities <- runif(10)
  best_positions <- particles
  global_best <- min(particles)
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  while (TRUE) {
    result <- optimize(particles, velocities, best_positions, global_best, w, c1, c2)
    particles <- result[[1]]
    velocities <- result[[2]]
    best_positions <- result[[3]]
    global_best <- min(best_positions)
  }
}

swarm()