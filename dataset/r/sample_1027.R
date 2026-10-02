update_velocity <- function(pos, vel, best_pos, global_best) {
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  r1 <- 0.5
  r2 <- 0.5
  new_vel <- w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos)
  return(new_vel)
}

update_position <- function(pos, vel) {
  return(pos + vel)
}

optimize <- function(func, bounds, n_particles = 30, max_iter = 1000) {
  particles <- seq(from = bounds[1], to = bounds[2], length.out = n_particles)
  velocities <- rep(0, n_particles)
  personal_best <- particles
  global_best <- particles[which.min(sapply(particles, func))]

  iterate <- function(i) {
    if (i < max_iter) {
      for (j in 1:n_particles) {
        velocities[j] <- update_velocity(particles[j], velocities[j], personal_best[j], global_best)
        particles[j] <- update_position(particles[j], velocities[j])
        if (func(particles[j]) < func(personal_best[j])) {
          personal_best[j] <- particles[j]
        }
      }
      global_best <- personal_best[which.min(sapply(personal_best, func))]
      iterate(i + 1)
    }
  }
  iterate(0)
}

main <- function() {
  test_func <- function(x) {
    return(x^2)
  }
  bounds <- c(-100, 100)
  optimize(test_func, bounds)
}

main()