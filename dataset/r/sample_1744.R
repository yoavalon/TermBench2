Swarm <- R6::R6Class("Swarm",
  public = list(
    size = NULL,
    dimensions = NULL,
    particles = NULL,
    initialize = function(size, dimensions) {
      self$size <- size
      self$dimensions <- dimensions
      self$particles <- lapply(1:size, function(_) Particle$new(dimensions))
    },
    update = function(global_best) {
      for (particle in self$particles) {
        particle$update(global_best)
      }
    }
  )
)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    initialize = function(dimensions) {
      self$position <- rep(0.0, dimensions)
      self$velocity <- rep(0.0, dimensions)
      self$best_position <- self$position
    },
    update = function(global_best) {
      w <- 0.7
      c1 <- 1.5
      c2 <- 1.5
      for (i in 1:length(self$position)) {
        r1 <- 0.6
        r2 <- 0.3
        velocity_component_1 <- w * self$velocity[i]
        velocity_component_2 <- c1 * r1 * (self$best_position[i] - self$position[i])
        velocity_component_3 <- c2 * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- velocity_component_1 + velocity_component_2 + velocity_component_3
        self$position[i] <- self$position[i] + self$velocity[i]
        if (self$position[i] < -10 || self$position[i] > 10) {
          self$position[i] <- self$best_position[i]
        }
      }
    }
  )
)

objective_function <- function(x) {
  return(sum(x^2))
}

main <- function() {
  dimensions <- 5
  swarm_size <- 10
  swarm <- Swarm$new(swarm_size, dimensions)
  global_best <- rep(0.0, dimensions)
  while (TRUE) {
    for (particle in swarm$particles) {
      if (objective_function(particle$position) < objective_function(global_best)) {
        global_best <- particle$position
      }
    }
    swarm$update(global_best)
  }
}

main()