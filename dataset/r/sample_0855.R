library(pracma)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_score = Inf,
    initialize = function(dimensions) {
      self$position <- runif(dimensions, -1, 1)
      self$velocity <- runif(dimensions, -1, 1)
      self$best_position <- self$position
    },
    update_velocity = function(global_best, inertia, cognitive, social) {
      for (i in 1:length(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        self$velocity[i] <- inertia * self$velocity[i] + cognitive * r1 * (self$best_position[i] - self$position[i]) + social * r2 * (global_best[i] - self$position[i])
      }
    },
    update_position = function() {
      for (i in 1:length(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
      }
    },
    evaluate = function(fitness_function) {
      self$score <- fitness_function(self$position)
      if (self$score < self$best_score) {
        self$best_score <- self$score
        self$best_position <- self$position
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    fitness_function = NULL,
    max_iterations = NULL,
    inertia = NULL,
    cognitive = NULL,
    social = NULL,
    global_best = NULL,
    global_best_score = Inf,
    initialize = function(size, dimensions, fitness_function, max_iterations, inertia, cognitive, social) {
      self$particles <- lapply(1:size, function(i) Particle$new(dimensions))
      self$fitness_function <- fitness_function
      self$max_iterations <- max_iterations
      self$inertia <- inertia
      self$cognitive <- cognitive
      self$social <- social
    },
    update_global_best = function() {
      for (particle in self$particles) {
        if (particle$best_score < self$global_best_score) {
          self$global_best_score <- particle$best_score
          self$global_best <- particle$best_position
        }
      }
    },
    optimize = function() {
      for (i in 1:self$max_iterations) {
        for (particle in self$particles) {
          particle$update_velocity(self$global_best, self$inertia, self$cognitive, self$social)
          particle$update_position()
          particle$evaluate(self$fitness_function)
        }
        self$update_global_best()
      }
    }
  )
)

sphere_function <- function(x) {
  return(sum(x^2))
}

main <- function() {
  dimensions <- 2
  size <- 30
  max_iterations <- 100
  inertia <- 0.5
  cognitive <- 1.5
  social <- 1.5
  swarm <- Swarm$new(size, dimensions, sphere_function, max_iterations, inertia, cognitive, social)
  swarm$optimize()
  cat('Best position:', swarm$global_best, '\n')
  cat('Best score:', swarm$global_best_score, '\n')
}

main()