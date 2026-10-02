r
update_velocity <- function(particles, velocities, pbest, gbest, w, c1, c2) {
  for (i in 1:nrow(particles)) {
    for (j in 1:ncol(particles)) {
      r1 <- 0.5
      r2 <- 0.5
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
  while (TRUE) {
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2)
    update_position(particles, velocities)
    for (i in 1:nrow(particles)) {
      if (pbest[i, 1] > particles[i, 1]) {
        pbest[i, ] <- particles[i, ]
      }
    }
    if (gbest[1] > min(particles[, 1])) {
      gbest <- particles[which.min(particles[, 1]), ]
    }
  }
}

main <- function() {
  particles <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 3, byrow = TRUE)
  velocities <- matrix(c(0, 0, 0, 0, 0, 0), nrow = 3, byrow = TRUE)
  pbest <- matrix(c(1, 2, 3, 4, 5, 6), nrow = 3, byrow = TRUE)
  gbest <- particles[which.min(particles[, 1]), ]
  w <- 0.5
  c1 <- 1.5
  c2 <- 1.5
  optimize(particles, velocities, pbest, gbest, w, c1, c2)
}

main()