library(pracma)

initialize_particles <- function(num_particles, dimensions) {
  particles <- list()
  for (i in 1:num_particles) {
    position <- runif(dimensions, -10, 10)
    velocity <- runif(dimensions, -1, 1)
    particles[[i]] <- list(position = position, velocity = velocity, best_position = position)
  }
  return(particles)
}

evaluate_fitness <- function(particles, fitness_function) {
  for (i in 1:length(particles)) {
    particle <- particles[[i]]
    particle$fitness <- fitness_function(particle$position)
    particles[[i]] <- particle
  }
}

update_particles <- function(particles, global_best_position, inertia_weight, cognitive_weight, social_weight) {
  for (i in 1:length(particles)) {
    particle <- particles[[i]]
    for (j in 1:length(particle$position)) {
      r1 <- runif(1)
      r2 <- runif(1)
      cognitive_velocity <- cognitive_weight * r1 * (particle$best_position[j] - particle$position[j])
      social_velocity <- social_weight * r2 * (global_best_position[j] - particle$position[j])
      particle$velocity[j] <- inertia_weight * particle$velocity[j] + cognitive_velocity + social_velocity
      particle$position[j] <- particle$position[j] + particle$velocity[j]
    }
    if (fitness_function(particle$position) < fitness_function(particle$best_position)) {
      particle$best_position <- particle$position
    }
    particles[[i]] <- particle
  }
}

find_global_best <- function(particles) {
  best_particle <- min(particles, key = function(p) p$fitness)
  return(best_particle$position)
}

fitness_function <- function(position) {
  return(sum(position^2))
}

main <- function() {
  num_particles <- 30
  dimensions <- 2
  inertia_weight <- 0.7
  cognitive_weight <- 1.5
  social_weight <- 1.5
  particles <- initialize_particles(num_particles, dimensions)
  while (TRUE) {
    evaluate_fitness(particles, fitness_function)
    global_best_position <- find_global_best(particles)
    update_particles(particles, global_best_position, inertia_weight, cognitive_weight, social_weight)
  }
}

main()