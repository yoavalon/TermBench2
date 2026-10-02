initialize_particles <- function(dim, num_particles) {
  particles <- replicate(num_particles, runif(dim), simplify = FALSE)
  velocities <- replicate(num_particles, runif(dim), simplify = FALSE)
  best_positions <- particles
  best_scores <- rep(Inf, num_particles)
  return(list(particles = particles, velocities = velocities, best_positions = best_positions, best_scores = best_scores))
}

update_particles <- function(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds) {
  for (i in 1:length(particles)) {
    for (j in 1:length(particles[[i]])) {
      r_p <- runif(1)
      r_g <- runif(1)
      velocities[[i]][[j]] <- omega * velocities[[i]][[j]] + phi_p * r_p * (best_positions[[i]][[j]] - particles[[i]][[j]]) + phi_g * r_g * (global_best[j] - particles[[i]][[j]])
      particles[[i]][[j]] <- particles[[i]][[j]] + velocities[[i]][[j]]
      particles[[i]][[j]] <- pmax(bounds[1], pmin(bounds[2], particles[[i]][[j]]))
    }
  }
  return(list(particles = particles, velocities = velocities))
}

main <- function() {
  dim <- 2
  num_particles <- 10
  result <- initialize_particles(dim, num_particles)
  particles <- result$particles
  velocities <- result$velocities
  best_positions <- result$best_positions
  best_scores <- result$best_scores
  global_best <- rep(Inf, dim)
  omega <- 0.7
  phi_p <- 0.2
  phi_g <- 0.3
  bounds <- c(0, 1)
  while (TRUE) {
    result <- update_particles(particles, velocities, best_positions, best_scores, global_best, omega, phi_p, phi_g, bounds)
    particles <- result$particles
    velocities <- result$velocities
  }
}

main()