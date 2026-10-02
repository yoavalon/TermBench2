library(stats)

set.seed(123)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_value = NULL,
    initialize = function(dimensions) {
      self$position <- runif(dimensions, -10, 10)
      self$velocity <- runif(dimensions, -1, 1)
      self$best_position <- self$position
      self$best_value <- self$calculate_value()
    },
    calculate_value = function() {
      return(sum(self$position^2))
    },
    update = function(global_best) {
      w <- 0.7
      c1 <- 1.5
      c2 <- 1.5
      for (i in seq_along(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        self$velocity[i] <- w * self$velocity[i] + c1 * r1 * (self$best_position[i] - self$position[i]) + c2 * r2 * (global_best[i] - self$position[i])
        self$position[i] <- self$position[i] + self$velocity[i]
      }
      self$value <- self$calculate_value()
      if (self$value < self$best_value) {
        self$best_value <- self$value
        self$best_position <- self$position
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    size = NULL,
    dimensions = NULL,
    particles = NULL,
    best_position = NULL,
    best_value = NULL,
    initialize = function(size, dimensions) {
      self$size <- size
      self$dimensions <- dimensions
      self$particles <- lapply(seq_len(size), function(_) Particle$new(dimensions))
      self$best_position <- NULL
      self$best_value <- Inf
    },
    update_best = function() {
      for (particle in self$particles) {
        if (particle$best_value < self$best_value) {
          self$best_value <- particle$best_value
          self$best_position <- particle$best_position
        }
      }
    },
    optimize = function(iterations) {
      for (_ in seq_len(iterations)) {
        for (particle in self$particles) {
          particle$update(self$best_position)
        }
        self$update_best()
      }
    }
  )
)

main <- function() {
  dimensions <- 2
  swarm_size <- 30
  iterations <- 100
  swarm <- Swarm$new(swarm_size, dimensions)
  swarm$optimize(iterations)
  cat('Best position:', swarm$best_position, '\n')
  cat('Best value:', swarm$best_value, '\n')
}

main()