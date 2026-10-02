library(MASS)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    initialize = function(dimensions) {
      self$position <- runif(dimensions, min = -10, max = 10)
      self$velocity <- runif(dimensions, min = -1, max = 1)
      self$best_position <- self$position
    },
    update_velocity = function(global_best, inertia, cognitive, social) {
      for (i in seq_along(self$velocity)) {
        r1 <- runif(1)
        r2 <- runif(1)
        self$velocity[i] <- inertia * self$velocity[i] + cognitive * r1 * (self$best_position[i] - self$position[i]) + social * r2 * (global_best[i] - self$position[i])
      }
    },
    update_position = function() {
      for (i in seq_along(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
      }
    },
    update_best_position = function(objective_function) {
      current_fitness <- objective_function(self$position)
      best_fitness <- objective_function(self$best_position)
      if (current_fitness < best_fitness) {
        self$best_position <- self$position
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    global_best = NULL,
    objective_function = NULL,
    initialize = function(dimensions, num_particles, objective_function) {
      self$particles <- lapply(1:num_particles, function(_) Particle$new(dimensions))
      self$global_best <- self$particles[[1]]$position
      self$objective_function <- objective_function
    },
    update_global_best = function() {
      for (particle in self$particles) {
        current_fitness <- self$objective_function(particle$position)
        global_best_fitness <- self$objective_function(self$global_best)
        if (current_fitness < global_best_fitness) {
          self$global_best <- particle$position
        }
      }
    },
    optimize = function(inertia, cognitive, social) {
      while (TRUE) {
        for (particle in self$particles) {
          particle$update_velocity(self$global_best, inertia, cognitive, social)
          particle$update_position()
          particle$update_best_position(self$objective_function)
        }
        self$update_global_best()
      }
    }
  )
)

objective_function <- function(x) {
  return(sum(x^2))
}

main <- function() {
  dimensions <- 2
  num_particles <- 30
  inertia <- 0.7
  cognitive <- 1.5
  social <- 1.5
  swarm <- Swarm$new(dimensions, num_particles, objective_function)
  swarm$optimize(inertia, cognitive, social)
}

main()