r
initialize_particles <- function(num_particles, num_dimensions) {
  particles <- list()
  for (i in 1:num_particles) {
    position <- runif(num_dimensions, -10, 10)
    velocity <- runif(num_dimensions, -1, 1)
    particles[[i]] <- list(position = position, velocity = velocity, best_position = position)
  }
  return(particles)
}

update_velocity <- function(particles, global_best, w, c1, c2) {
  for (particle in particles) {
    r1 <- runif(1)
    r2 <- runif(1)
    for (i in 1:length(particle$position)) {
      cognitive_velocity <- c1 * r1 * (particle$best_position[i] - particle$position[i])
      social_velocity <- c2 * r2 * (global_best$position[i] - particle$position[i])
      particle$velocity[i] <- w * particle$velocity[i] + cognitive_velocity + social_velocity
    }
  }
}

update_position <- function(particles) {
  for (particle in particles) {
    for (i in 1:length(particle$position)) {
      particle$position[i] <- particle$position[i] + particle$velocity[i]
    }
  }
}

evaluate_fitness <- function(particles, fitness_function) {
  for (particle in particles) {
    fitness <- fitness_function(particle$position)
    if (fitness < fitness_function(particle$best_position)) {
      particle$best_position <- particle$position
    }
  }
  return(particles[[which.min(sapply(particles, function(x) fitness_function(x$best_position)))]]$best_position)
}

main <- function() {
  num_particles <- 20
  num_dimensions <- 2
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  max_iterations <- 100

  fitness_function <- function(position) {
    return(sum(position^2))
  }
  
  particles <- initialize_particles(num_particles, num_dimensions)
  global_best <- evaluate_fitness(particles, fitness_function)
  
  for (i in 1:max_iterations) {
    update_velocity(particles, global_best, w, c1, c2)
    update_position(particles)
    global_best <- evaluate_fitness(particles, fitness_function)
  }
  
  print(paste('Best position found:', global_best))
  print(paste('Fitness value:', fitness_function(global_best)))
}

main()