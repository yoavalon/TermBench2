Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    pbest = NULL,
    pbest_value = NULL,
    initialize = function(dim) {
      self$position <- rep(0.0, dim)
      self$velocity <- rep(0.0, dim)
      self$pbest <- rep(0.0, dim)
      self$pbest_value <- Inf
    },
    update_velocity = function(gbest, w = 0.7, c1 = 1.5, c2 = 1.5) {
      for (i in 1:length(self$position)) {
        r1 <- 0.5
        r2 <- 0.5
        self$velocity[i] <- w * self$velocity[i] + c1 * r1 * (self$pbest[i] - self$position[i]) + c2 * r2 * (gbest[i] - self$position[i])
      }
    },
    update_position = function(bounds) {
      for (i in 1:length(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
        self$position[i] <- max(bounds[i][1], min(bounds[i][2], self$position[i]))
      }
    },
    update_pbest = function(value) {
      if (value < self$pbest_value) {
        self$pbest <- self$position
        self$pbest_value <- value
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    gbest = NULL,
    gbest_value = NULL,
    bounds = NULL,
    initialize = function(num_particles, dim, bounds) {
      self$particles <- lapply(1:num_particles, function(_) Particle$new(dim))
      self$gbest <- rep(0.0, dim)
      self$gbest_value <- Inf
      self$bounds <- bounds
    },
    update_gbest = function() {
      for (particle in self$particles) {
        if (particle$pbest_value < self$gbest_value) {
          self$gbest <- particle$pbest
          self$gbest_value <- particle$pbest_value
        }
      }
    },
    iterate = function() {
      for (particle in self$particles) {
        particle$update_velocity(self$gbest)
        particle$update_position(self$bounds)
        particle$update_pbest(objective_function(particle$position))
      }
    }
  )
)

objective_function <- function(x) {
  return(sum(x^2))
}

optimize <- function(num_particles, dim, max_iterations, bounds) {
  swarm <- Swarm$new(num_particles, dim, bounds)
  for (i in 1:max_iterations) {
    swarm$iterate()
    swarm$update_gbest()
  }
  return(list(swarm$gbest, swarm$gbest_value))
}

main <- function() {
  num_particles <- 30
  dim <- 2
  max_iterations <- 100
  bounds <- list(c(-10, 10), c(-10, 10))
  best_position <- optimize(num_particles, dim, max_iterations, bounds)[[1]]
  best_value <- optimize(num_particles, dim, max_iterations, bounds)[[2]]
  cat('Best position:', best_position, '\n')
  cat('Best value:', best_value, '\n')
}

main()