library(stats)

initialize_particles <- function(dimensions, count) {
  particles <- list()
  for (i in 1:count) {
    position <- runif(dimensions, -10, 10)
    velocity <- runif(dimensions, -1, 1)
    particles[[i]] <- list(position = position, velocity = velocity, best_position = position)
  }
  return(particles)
}

evaluate_fitness <- function(particles, objective_function) {
  for (particle in particles) {
    particle$fitness <- objective_function(particle$position)
  }
}

update_particles <- function(particles, global_best, inertia_weight, cognitive_weight, social_weight) {
  for (particle in particles) {
    for (i in 1:length(particle$position)) {
      r1 <- runif(1)
      r2 <- runif(1)
      cognitive_velocity <- cognitive_weight * r1 * (particle$best_position[i] - particle$position[i])
      social_velocity <- social_weight * r2 * (global_best$position[i] - particle$position[i])
      particle$velocity[i] <- inertia_weight * particle$velocity[i] + cognitive_velocity + social_velocity
      particle$position[i] <- particle$position[i] + particle$velocity[i]
    }
    particle$best_position <- ifelse(particle$fitness < particle$fitness, particle$position, particle$best_position)
  }
}

find_global_best <- function(particles) {
  global_best <- particles[[1]]
  for (particle in particles[2:length(particles)]) {
    if (particle$fitness < global_best$fitness) {
      global_best <- particle
    }
  }
  return(global_best)
}

objective_function <- function(position) {
  return(sum(position^2))
}

main <- function() {
  dimensions <- 2
  particle_count <- 30
  inertia_weight <- 0.7
  cognitive_weight <- 1.5
  social_weight <- 1.5
  particles <- initialize_particles(dimensions, particle_count)
  while (TRUE) {
    evaluate_fitness(particles, objective_function)
    global_best <- find_global_best(particles)
    update_particles(particles, global_best, inertia_weight, cognitive_weight, social_weight)
  }
}

main()