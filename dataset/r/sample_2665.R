library(pracma)

Particle <- R6::R6Class(
  "Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_fitness = Inf,
    
    initialize = function(dimensions, bounds) {
      self$position <- sapply(bounds, function(b) runif(1, min = b[1], max = b[2]))
      self$velocity <- sapply(1:dimensions, function(_) runif(1, min = -1, max = 1))
      self$best_position <- self$position
      self$best_fitness <- Inf
    },
    
    update_velocity = function(global_best, w, c1, c2) {
      for (i in 1:length(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (self$best_position[i] - self$position[i])
        social <- c2 * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive + social
      }
    },
    
    update_position = function(bounds) {
      for (i in 1:length(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
        self$position[i] <- max(bounds[[i]][1], min(self$position[i], bounds[[i]][2]))
      }
    },
    
    evaluate = function(fitness_function) {
      self$best_fitness <- min(self$best_fitness, fitness_function(self$position))
    }
  )
)

optimize <- function(fitness_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations) {
  particles <- lapply(1:num_particles, function(_) Particle$new(dimensions, bounds))
  global_best <- rep(Inf, dimensions)
  global_best_fitness <- Inf
  for (iteration in 1:max_iterations) {
    for (particle in particles) {
      particle$evaluate(fitness_function)
      if (particle$best_fitness < global_best_fitness) {
        global_best_fitness <- particle$best_fitness
        global_best <- particle$best_position
      }
    }
    for (particle in particles) {
      particle$update_velocity(global_best, w, c1, c2)
      particle$update_position(bounds)
    }
  }
  return(list(global_best, global_best_fitness))
}

main <- function() {
  sphere_function <- function(x) {
    sum(x^2)
  }
  dimensions <- 3
  bounds <- replicate(dimensions, c(-5.12, 5.12), simplify = FALSE)
  num_particles <- 30
  w <- 0.729
  c1 <- 1.494
  c2 <- 1.494
  max_iterations <- 100
  result <- optimize(sphere_function, dimensions, bounds, num_particles, w, c1, c2, max_iterations)
  cat('Best position:', result[[1]], '\n')
  cat('Best fitness:', result[[2]], '\n')
}

main()