library(MASS)

Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    best_score = "numeric"
  ),
  methods = list(
    initialize = function(dimensions) {
      .self$position <- runif(dimensions, -10, 10)
      .self$velocity <- runif(dimensions, -1, 1)
      .self$best_position <- .self$position
      .self$best_score <- Inf
    },
    update_velocity = function(global_best_position, w, c1, c2) {
      for (i in 1:length(.self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
        social <- c2 * r2 * (global_best_position[i] - .self$position[i])
        .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
      }
    },
    update_position = function() {
      for (i in 1:length(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
      }
    },
    evaluate = function(fitness_function) {
      .self$best_score <- fitness_function(.self$position)
      return(.self$best_score)
    }
  )
)

Swarm <- setRefClass("Swarm",
  fields = list(
    particles = "list",
    global_best_position = "numeric",
    global_best_score = "numeric"
  ),
  methods = list(
    initialize = function(num_particles, dimensions) {
      .self$particles <- lapply(1:num_particles, function(i) Particle$new(dimensions))
      .self$global_best_position <- runif(dimensions, -10, 10)
      .self$global_best_score <- Inf
    },
    update_global_best = function() {
      for (particle in .self$particles) {
        if (particle$best_score < .self$global_best_score) {
          .self$global_best_score <- particle$best_score
          .self$global_best_position <- particle$best_position
        }
      }
    }
  )
)

fitness_function <- function(x) {
  return(sum(x^2))
}

optimize <- function(swarm, w, c1, c2, iterations) {
  for (i in 1:iterations) {
    for (particle in swarm$particles) {
      particle$update_velocity(swarm$global_best_position, w, c1, c2)
      particle$update_position()
      particle$evaluate(fitness_function)
    }
    swarm$update_global_best()
  }
  return(list(swarm$global_best_position, swarm$global_best_score))
}

main <- function() {
  dimensions <- 10
  num_particles <- 20
  w <- 0.7
  c1 <- 2.0
  c2 <- 2.0
  iterations <- 100
  swarm <- Swarm$new(num_particles, dimensions)
  best_position <- optimize(swarm, w, c1, c2, iterations)[[1]]
  best_score <- optimize(swarm, w, c1, c2, iterations)[[2]]
  cat('Best position:', best_position, '\n')
  cat('Best score:', best_score, '\n')
}

main()