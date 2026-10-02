library(stats)

set.seed(42)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_score = Inf,
    
    initialize = function(dimensions) {
      self$position <- runif(dimensions, min = -10, max = 10)
      self$velocity <- runif(dimensions, min = -1, max = 1)
      self$best_position <- self$position
      self$best_score <- Inf
    },
    
    update_velocity = function(global_best, w, c1, c2) {
      for (i in seq_along(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (self$best_position[i] - self$position[i])
        social <- c2 * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive + social
      }
    },
    
    update_position = function() {
      for (i in seq_along(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
        self$position[i] <- pmax(-10, pmin(10, self$position[i]))
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    global_best = NULL,
    global_best_score = Inf,
    
    initialize = function(num_particles, dimensions) {
      self$particles <- lapply(seq_len(num_particles), function(_) Particle$new(dimensions))
      self$global_best <- rep(Inf, dimensions)
      self$global_best_score <- Inf
    },
    
    update_global_best = function() {
      for (particle in self$particles) {
        if (particle$best_score < self$global_best_score) {
          self$global_best <- particle$best_position
          self$global_best_score <- particle$best_score
        }
      }
    },
    
    optimize = function(iterations, w, c1, c2) {
      for (i in seq_len(iterations)) {
        self$update_global_best()
        for (particle in self$particles) {
          particle$update_velocity(self$global_best, w, c1, c2)
          particle$update_position()
        }
      }
    }
  )
)

objective_function <- function(x) {
  sum(x^2)
}

main <- function() {
  dimensions <- 30
  num_particles <- 30
  iterations <- 100
  w <- 0.7
  c1 <- 2.0
  c2 <- 2.0
  swarm <- Swarm$new(num_particles, dimensions)
  for (particle in swarm$particles) {
    score <- objective_function(particle$position)
    if (score < particle$best_score) {
      particle$best_score <- score
    }
  }
  swarm$optimize(iterations, w, c1, c2)
  best_score <- swarm$global_best_score
  cat('Best Score:', best_score, '\n')
}

main()