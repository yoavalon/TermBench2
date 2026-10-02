library(MASS)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_score = Inf,
    
    initialize = function(dimensions) {
      self$position <- runif(dimensions, -10, 10)
      self$velocity <- runif(dimensions, -1, 1)
      self$best_position <- self$position
    },
    
    update_velocity = function(global_best_position, w = 0.7, c1 = 1.5, c2 = 1.5) {
      for (i in seq_along(self$velocity)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (self$best_position[i] - self$position[i])
        social <- c2 * r2 * (global_best_position[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive + social
      }
    },
    
    update_position = function() {
      for (i in seq_along(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
      }
    },
    
    evaluate = function(cost_function) {
      score <- cost_function(self$position)
      if (score < self$best_score) {
        self$best_score <- score
        self$best_position <- self$position
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    global_best_position = NULL,
    global_best_score = Inf,
    
    initialize = function(size, dimensions) {
      self$particles <- replicate(size, Particle$new(dimensions), simplify = FALSE)
      self$global_best_position <- self$particles[[1]]$position
    },
    
    update_global_best = function() {
      for (particle in self$particles) {
        if (particle$best_score < self$global_best_score) {
          self$global_best_score <- particle$best_score
          self$global_best_position <- particle$best_position
        }
      }
    },
    
    update_swarm = function() {
      for (particle in self$particles) {
        particle$update_velocity(self$global_best_position)
        particle$update_position()
      }
    }
  )
)

cost_function <- function(position) {
  sum(position^2)
}

main <- function() {
  dimensions <- 10
  swarm_size <- 20
  swarm <- Swarm$new(swarm_size, dimensions)
  while (TRUE) {
    for (particle in swarm$particles) {
      particle$evaluate(cost_function)
    }
    swarm$update_global_best()
    swarm$update_swarm()
  }
}

main()