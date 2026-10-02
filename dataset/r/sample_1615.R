library(stats)

initialize_particles <- function(dimensions, population_size) {
  particles <- list()
  for (i in 1:population_size) {
    position <- runif(dimensions, min = -10, max = 10)
    velocity <- rep(0, dimensions)
    best_position <- position
    particles[[i]] <- list(position = position, velocity = velocity, best_position = best_position)
  }
  return(particles)
}

update_particles <- function(particles, global_best) {
  for (particle in particles) {
    for (i in 1:length(particle$position)) {
      r1 <- runif(1)
      r2 <- runif(1)
      cognitive_velocity <- r1 * (particle$best_position[i] - particle$position[i])
      social_velocity <- r2 * (global_best$position[i] - particle$position[i])
      particle$velocity[i] <- 0.7 * particle$velocity[i] + cognitive_velocity + social_velocity
      particle$position[i] <- particle$position[i] + particle$velocity[i]
    }
    if (evaluate(particle$position) < evaluate(particle$best_position)) {
      particle$best_position <- particle$position
    }
  }
}

evaluate <- function(position) {
  return(sum(position^2))
}

find_global_best <- function(particles) {
  return(particles[[which.min(sapply(particles, function(x) evaluate(x$position)))])
}

main <- function() {
  dimensions <- 2
  population_size <- 10
  particles <- initialize_particles(dimensions, population_size)
  global_best <- find_global_best(particles)
  while (TRUE) {
    update_particles(particles, global_best)
    global_best <- find_global_best(particles)
  }
}

main()