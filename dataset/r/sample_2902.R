library(pracma)

Particle <- R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_fitness = Inf,
    
    initialize = function(dimensions) {
      self$position <- runif(dimensions, -1, 1)
      self$velocity <- runif(dimensions, -1, 1)
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
        self$position[i] <- pmin(pmax(self$position[i], bounds[1, i]), bounds[2, i])
      }
    },
    
    evaluate_fitness = function(fitness_function) {
      self$fitness <- fitness_function(self$position)
      if (self$fitness < self$best_fitness) {
        self$best_fitness <- self$fitness
        self$best_position <- self$position
      }
    }
  )
)

Swarm <- R6Class("Swarm",
  public = list(
    particles = NULL,
    global_best = NULL,
    global_best_fitness = Inf,
    fitness_function = NULL,
    bounds = NULL,
    
    initialize = function(num_particles, dimensions, bounds, fitness_function) {
      self$particles <- lapply(1:num_particles, function(_) Particle$new(dimensions))
      self$global_best <- runif(dimensions, -1, 1)
      self$global_best_fitness <- Inf
      self$fitness_function <- fitness_function
      self$bounds <- bounds
    },
    
    update_global_best = function() {
      for (particle in self$particles) {
        if (particle$best_fitness < self$global_best_fitness) {
          self$global_best_fitness <- particle$best_fitness
          self$global_best <- particle$best_position
        }
      }
    },
    
    optimize = function(w, c1, c2) {
      while (TRUE) {
        for (particle in self$particles) {
          particle$update_velocity(self$global_best, w, c1, c2)
          particle$update_position(self$bounds)
          particle$evaluate_fitness(self$fitness_function)
        }
        self$update_global_best()
      }
    }
  )
)

fitness_function <- function(x) {
  sum(x^2)
}

main <- function() {
  dimensions <- 2
  num_particles <- 30
  bounds <- rbind(c(-10, -10), c(10, 10))
  swarm <- Swarm$new(num_particles, dimensions, bounds, fitness_function)
  w <- 0.729
  c1 <- 1.494
  c2 <- 1.494
  swarm$optimize(w, c1, c2)
}

main()