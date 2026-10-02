library(particle swarm)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_value = Inf,
    
    initialize = function(dimensions) {
      self$position <- runif(dimensions, -1, 1)
      self$velocity <- runif(dimensions, -1, 1)
      self$best_position <- self$position
      self$best_value <- Inf
    },
    
    update_velocity = function(global_best, w = 0.7, c1 = 1.5, c2 = 1.5) {
      for (i in 1:length(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (self$best_position[i] - self$position[i])
        social <- c2 * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive + social
      }
    },
    
    update_position = function() {
      for (i in 1:length(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
      }
    },
    
    evaluate = function(objective_function) {
      self$best_value <- objective_function(self$position)
      if (self$best_value < self$best_value) {
        self$best_position <- self$position
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    global_best = NULL,
    global_best_value = Inf,
    
    initialize = function(dimensions, num_particles) {
      self$particles <- lapply(1:num_particles, function(_) Particle$new(dimensions))
      self$global_best <- rep(Inf, dimensions)
      self$global_best_value <- Inf
    },
    
    update_global_best = function() {
      for (particle in self$particles) {
        if (particle$best_value < self$global_best_value) {
          self$global_best_value <- particle$best_value
          self$global_best <- particle$best_position
        }
      }
    },
    
    iterate = function(objective_function) {
      for (particle in self$particles) {
        particle$update_velocity(self$global_best)
        particle$update_position()
        particle$evaluate(objective_function)
      }
      self$update_global_best()
    }
  )
)

objective_function <- function(x) {
  sum(x^2)
}

optimize <- function(dimensions, num_particles, max_iterations) {
  swarm <- Swarm$new(dimensions, num_particles)
  for (i in 1:max_iterations) {
    swarm$iterate(objective_function)
  }
  return(swarm$global_best)
}

main <- function() {
  dimensions <- 10
  num_particles <- 20
  max_iterations <- 100
  best_solution <- optimize(dimensions, num_particles, max_iterations)
  cat('Best solution:', best_solution, '\n')
}

main()