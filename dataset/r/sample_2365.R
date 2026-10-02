initialize_particles <- function(dim, num_particles) {
  particles <- replicate(num_particles, runif(dim, -10, 10))
  velocities <- replicate(num_particles, runif(dim, -1, 1))
  pbest_positions <- particles
  pbest_values <- rep(Inf, num_particles)
  gbest_position <- NULL
  gbest_value <- Inf
  return(list(particles = particles, velocities = velocities, pbest_positions = pbest_positions, pbest_values = pbest_values, gbest_position = gbest_position, gbest_value = gbest_value))
}

update_pbest <- function(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func) {
  for (i in 1:length(particles)) {
    current_value <- fitness_func(particles[[i]])
    if (current_value < pbest_values[i]) {
      pbest_values[i] <- current_value
      pbest_positions[[i]] <- particles[[i]]
    }
    if (current_value < gbest_value) {
      gbest_value <- current_value
      gbest_position <- particles[[i]]
    }
  }
  return(list(gbest_value = gbest_value, gbest_position = gbest_position, pbest_values = pbest_values, pbest_positions = pbest_positions))
}

update_particles <- function(particles, velocities, pbest_positions, gbest_position, w, c1, c2) {
  for (i in 1:length(particles)) {
    for (j in 1:length(particles[[i]])) {
      r1 <- runif(1)
      r2 <- runif(1)
      velocities[[i]][j] <- w * velocities[[i]][j] + c1 * r1 * (pbest_positions[[i]][j] - particles[[i]][j]) + c2 * r2 * (gbest_position[j] - particles[[i]][j])
      particles[[i]][j] <- particles[[i]][j] + velocities[[i]][j]
    }
  }
}

fitness_func <- function(position) {
  return(sum(position^2))
}

main <- function() {
  dim <- 2
  num_particles <- 10
  w <- 0.729
  c1 <- 1.494
  c2 <- 1.494
  result <- initialize_particles(dim, num_particles)
  particles <- result$particles
  velocities <- result$velocities
  pbest_positions <- result$pbest_positions
  pbest_values <- result$pbest_values
  gbest_position <- result$gbest_position
  gbest_value <- result$gbest_value
  while (TRUE) {
    result <- update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func)
    gbest_value <- result$gbest_value
    gbest_position <- result$gbest_position
    pbest_values <- result$pbest_values
    pbest_positions <- result$pbest_positions
    update_particles(particles, velocities, pbest_positions, gbest_position, w, c1, c2)
  }
}

main()