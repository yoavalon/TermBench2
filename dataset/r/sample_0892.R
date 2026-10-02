library(stats)

initialize_particles <- function(size, dimensions, lower_bound, upper_bound) {
  particles <- replicate(size, runif(dimensions, min = lower_bound, max = upper_bound), simplify = FALSE)
  return(particles)
}

evaluate_fitness <- function(particles, objective_function) {
  fitness <- sapply(particles, objective_function)
  return(fitness)
}

update_particles <- function(particles, velocities, pbest, gbest, w, c1, c2) {
  new_particles <- list()
  for (i in 1:length(particles)) {
    r1 <- runif(1)
    r2 <- runif(1)
    velocity <- mapply(function(d) {
      w * velocities[[i]][[d]] + c1 * r1 * (pbest[[i]][[d]] - particles[[i]][[d]]) + c2 * r2 * (gbest[[d]] - particles[[i]][[d]])
    }, 1:length(particles[[i]]))
    new_position <- mapply(function(d) {
      particles[[i]][[d]] + velocity[[d]]
    }, 1:length(particles[[i]]))
    new_particles[[i]] <- new_position
  }
  return(list(new_particles, velocity))
}

optimize <- function(objective_function, dimensions, bounds, size, iterations, w, c1, c2) {
  particles <- initialize_particles(size, dimensions, bounds[1], bounds[2])
  velocities <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
  pbest <- particles
  pbest_fitness <- evaluate_fitness(pbest, objective_function)
  gbest <- pbest[[which.min(pbest_fitness)]]
  gbest_fitness <- min(pbest_fitness)
  for (i in 1:iterations) {
    result <- update_particles(particles, velocities, pbest, gbest, w, c1, c2)
    particles <- result[[1]]
    velocities <- result[[2]]
    fitness <- evaluate_fitness(particles, objective_function)
    for (j in 1:size) {
      if (fitness[j] < pbest_fitness[j]) {
        pbest[[j]] <- particles[[j]]
        pbest_fitness[j] <- fitness[j]
      }
    }
    if (min(fitness) < gbest_fitness) {
      gbest <- particles[[which.min(fitness)]]
      gbest_fitness <- min(fitness)
    }
  }
  return(list(gbest, gbest_fitness))
}

sphere_function <- function(x) {
  return(sum(x^2))
}

main <- function() {
  dimensions <- 2
  bounds <- c(-10, 10)
  size <- 30
  iterations <- 100
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  best_solution <- optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2)[[1]]
  best_fitness <- optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2)[[2]]
  print(paste('Best solution:', best_solution))
  print(paste('Best fitness:', best_fitness))
}

main()