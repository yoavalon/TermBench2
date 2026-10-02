library(R6)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_score = Inf,
    
    initialize = function(dimensions, search_space) {
      self$position <- runif(dimensions, min = search_space[1], max = search_space[2])
      self$velocity <- rep(0.0, times = dimensions)
      self$best_position <- self$position
      self$best_score <- Inf
    },
    
    update_velocity = function(global_best) {
      inertia = 0.5
      cognitive_factor = 1.5
      social_factor = 1.5
      for (i in seq_along(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- cognitive_factor * r1 * (self$best_position[i] - self$position[i])
        social <- social_factor * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- inertia * self$velocity[i] + cognitive + social
      }
    },
    
    move = function() {
      self$position <- self$position + self$velocity
    },
    
    evaluate = function() {
      self$score <- self$objective_function()
      if (self$score < self$best_score) {
        self$best_score <- self$score
        self$best_position <- self$position
      }
    },
    
    objective_function = function() {
      return(sum(self$position^2))
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    size = NULL,
    dimensions = NULL,
    search_space = NULL,
    particles = NULL,
    best_position = NULL,
    best_score = Inf,
    
    initialize = function(size, dimensions, search_space) {
      self$size <- size
      self$dimensions <- dimensions
      self$search_space <- search_space
      self$particles <- replicate(size, Particle$new(dimensions, search_space), simplify = FALSE)
      self$best_position <- self$particles[sample(1:size, 1)]$position
      self$best_score <- Inf
    },
    
    update_best_position = function() {
      for (particle in self$particles) {
        if (particle$score < self$best_score) {
          self$best_score <- particle$score
          self$best_position <- particle$position
        }
      }
    },
    
    iterate = function() {
      for (particle in self$particles) {
        particle$update_velocity(self$best_position)
        particle$move()
        particle$evaluate()
      }
    },
    
    run = function(iterations) {
      for (i in 1:iterations) {
        self$iterate()
        self$update_best_position()
      }
    }
  )
)

main <- function() {
  swarm_size <- 30
  dimensions <- 2
  search_space <- c(-10, 10)
  iterations <- 100
  swarm <- Swarm$new(swarm_size, dimensions, search_space)
  swarm$run(iterations)
  cat('Best position:', swarm$best_position, '\n')
  cat('Best score:', swarm$best_score, '\n')
}

main()