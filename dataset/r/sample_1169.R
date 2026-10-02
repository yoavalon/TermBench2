Swarm <- function(size, dimensions) {
  particles <- replicate(size, Particle(dimensions), simplify = FALSE)
  gbest <- particles[[1]]
  
  update_gbest <- function() {
    for (particle in particles) {
      if (particle$fitness < gbest$fitness) {
        gbest <<- particle
      }
    }
  }
  
  optimize <- function() {
    while (TRUE) {
      for (particle in particles) {
        particle$update_velocity(gbest)
        particle$update_position()
      }
      update_gbest()
    }
  }
  
  return(list(
    particles = particles,
    gbest = gbest,
    update_gbest = update_gbest,
    optimize = optimize
  ))
}

Particle <- function(dimensions) {
  position <- rep(0.0, dimensions)
  velocity <- rep(0.0, dimensions)
  best_position <- position
  fitness <- Inf
  
  update_velocity <- function(gbest) {
    for (i in 1:length(position)) {
      r1 <- 0.5
      r2 <- 0.5
      inertia <- 0.7
      velocity[i] <<- inertia * velocity[i] + r1 * (best_position[i] - position[i]) + r2 * (gbest$position[i] - position[i])
    }
  }
  
  update_position <- function() {
    for (i in 1:length(position)) {
      position[i] <<- position[i] + velocity[i]
      if (fitness > calculate_fitness()) {
        best_position <<- position
        fitness <<- calculate_fitness()
      }
    }
  }
  
  calculate_fitness <- function() {
    return(sum(position^2))
  }
  
  return(list(
    position = position,
    velocity = velocity,
    best_position = best_position,
    fitness = fitness,
    update_velocity = update_velocity,
    update_position = update_position,
    calculate_fitness = calculate_fitness
  ))
}

main <- function() {
  swarm <- Swarm(10, 2)
  swarm$optimize()
}

main()