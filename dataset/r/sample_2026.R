r
library(runif)

initialize_particles <- function(size, dimensions) {
  particles <- list()
  for (i in 1:size) {
    position <- runif(dimensions, min = -10, max = 10)
    velocity <- runif(dimensions, min = -1, max = 1)
    pbest_position <- position
    pbest_value <- Inf
    particles[[i]] <- list(position = position, velocity = velocity, pbest_position = pbest_position, pbest_value = pbest_value)
  }
  return(particles)
}

update_velocity <- function(particles, gbest_position, w = 0.7, c1 = 1.5, c2 = 1.5) {
  for (particle in particles) {
    for (i in 1:length(particle$position)) {
      r1 <- runif(1)
      r2 <- runif(1)
      cognitive <- c1 * r1 * (particle$pbest_position[i] - particle$position[i])
      social <- c2 * r2 * (gbest_position[i] - particle$position[i])
      particle$velocity[i] <- w * particle$velocity[i] + cognitive + social
    }
  }
}

update_position <- function(particles, bounds) {
  for (particle in particles) {
    for (i in 1:length(particle$position)) {
      particle$position[i] <- particle$position[i] + particle$velocity[i]
      particle$position[i] <- pmax(bounds[1], pmin(particle$position[i], bounds[2]))
    }
  }
}

evaluate <- function(particles, objective_function) {
  for (particle in particles) {
    value <- objective_function(particle$position)
    if (value < particle$pbest_value) {
      particle$pbest_value <- value
      particle$pbest_position <- particle$position
    }
  }
}

find_gbest <- function(particles) {
  gbest_value <- Inf
  gbest_position <- NULL
  for (particle in particles) {
    if (particle$pbest_value < gbest_value) {
      gbest_value <- particle$pbest_value
      gbest_position <- particle$pbest_position
    }
  }
  return(gbest_position)
}

optimize <- function(objective_function, dimensions, size, iterations, bounds) {
  particles <- initialize_particles(size, dimensions)
  gbest_position <- find_gbest(particles)
  for (i in 1:iterations) {
    update_velocity(particles, gbest_position)
    update_position(particles, bounds)
    evaluate(particles, objective_function)
    gbest_position <- find_gbest(particles)
  }
  return(gbest_position)
}

main <- function() {
  sphere_function <- function(x) {
    return(sum(x^2))
  }
  dimensions <- 30
  size <- 30
  iterations <- 100
  bounds <- c(-10, 10)
  result <- optimize(sphere_function, dimensions, size, iterations, bounds)
  print(result)
}

main()