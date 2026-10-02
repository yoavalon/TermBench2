library(stats)

Particle <- setRefClass(
  "Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    best_score = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, lower_bound, upper_bound) {
      .self$position <- runif(dimensions, min = lower_bound, max = upper_bound)
      .self$velocity <- runif(dimensions, min = -1, max = 1)
      .self$best_position <- .self$position
      .self$best_score <- Inf
    },
    update_velocity = function(global_best_position, w, c1, c2) {
      for (i in 1:length(.self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        .self$velocity[i] <- w * .self$velocity[i] + c1 * r1 * (.self$best_position[i] - .self$position[i]) + c2 * r2 * (global_best_position[i] - .self$position[i])
      }
    },
    update_position = function() {
      for (i in 1:length(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
      }
    },
    evaluate = function(fitness_function) {
      current_score <- fitness_function(.self$position)
      .self$best_score <- min(.self$best_score, current_score)
      if (current_score < .self$best_score) {
        .self$best_position <- .self$position
      }
    }
  )
)

Swarm <- setRefClass(
  "Swarm",
  fields = list(
    particles = "list",
    global_best_position = "numeric",
    global_best_score = "numeric"
  ),
  methods = list(
    initialize = function(size, dimensions, lower_bound, upper_bound) {
      .self$particles <- replicate(size, Particle$new(dimensions, lower_bound, upper_bound), simplify = FALSE)
      .self$global_best_position <- runif(dimensions, min = lower_bound, max = upper_bound)
      .self$global_best_score <- Inf
    },
    update_global_best = function() {
      for (particle in .self$particles) {
        if (particle$best_score < .self$global_best_score) {
          .self$global_best_score <- particle$best_score
          .self$global_best_position <- particle$best_position
        }
      }
    },
    iterate = function(fitness_function, w, c1, c2) {
      for (particle in .self$particles) {
        particle$update_velocity(.self$global_best_position, w, c1, c2)
        particle$update_position()
        particle$evaluate(fitness_function)
      }
      .self$update_global_best()
    }
  )
)

fitness_function <- function(position) {
  sum(position^2)
}

main <- function() {
  dimensions <- 2
  lower_bound <- -10
  upper_bound <- 10
  swarm_size <- 30
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- 100
  swarm <- Swarm$new(swarm_size, dimensions, lower_bound, upper_bound)
  for (i in 1:iterations) {
    swarm$iterate(fitness_function, w, c1, c2)
  }
  cat('Global best score:', swarm$global_best_score, '\n')
  cat('Global best position:', swarm$global_best_position, '\n')
}

main()