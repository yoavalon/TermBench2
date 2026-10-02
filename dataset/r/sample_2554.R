library(stats)

initialize_particles <- function(num_particles, dimensions) {
  return(replicate(num_particles, runif(dimensions, -1, 1), simplify = FALSE))
}

evaluate_fitness <- function(position, target) {
  return(sum((position - target)^2))
}

update_velocity <- function(velocity, position, p_best, g_best, w, c1, c2) {
  r1 <- runif(1)
  r2 <- runif(1)
  return(velocity * w + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position))
}

update_position <- function(position, velocity) {
  return(position + velocity)
}

particle_swarm <- function(num_particles, dimensions, target, max_iterations) {
  particles <- initialize_particles(num_particles, dimensions)
  velocities <- replicate(num_particles, rep(0, dimensions), simplify = FALSE)
  p_best <- particles
  g_best <- particles[which.min(sapply(particles, function(x) evaluate_fitness(x, target))), ]
  for (i in 1:max_iterations) {
    for (j in 1:num_particles) {
      if (evaluate_fitness(particles[[j]], target) < evaluate_fitness(p_best[[j]], target)) {
        p_best[[j]] <- particles[[j]]
      }
    }
    g_best <- p_best[which.min(sapply(p_best, function(x) evaluate_fitness(x, target))), ]
    for (j in 1:num_particles) {
      velocities[[j]] <- update_velocity(velocities[[j]], particles[[j]], p_best[[j]], g_best, 0.7, 1.5, 1.5)
      particles[[j]] <- update_position(particles[[j]], velocities[[j]])
    }
  }
  return(g_best)
}

main <- function() {
  target <- c(0, 0)
  result <- particle_swarm(30, 2, target, 100)
  print(result)
}

main()