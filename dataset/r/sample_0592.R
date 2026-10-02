Swarm <- setRefClass("Swarm",
  fields = list(
    size = "numeric",
    dimensions = "numeric",
    particles = "matrix",
    velocities = "matrix",
    best_positions = "matrix",
    best_scores = "numeric",
    global_best = "numeric",
    global_best_score = "numeric"
  ),
  methods = list(
    initialize = function(size, dimensions) {
      .self$size <- size
      .self$dimensions <- dimensions
      .self$particles <- matrix(0.0, nrow = size, ncol = dimensions)
      .self$velocities <- matrix(0.0, nrow = size, ncol = dimensions)
      .self$best_positions <- matrix(0.0, nrow = size, ncol = dimensions)
      .self$best_scores <- rep(Inf, size)
      .self$global_best <- rep(0.0, dimensions)
      .self$global_best_score <- Inf
    },
    update_global_best = function() {
      for (i in 1:.self$size) {
        if (.self$best_scores[i] < .self$global_best_score) {
          .self$global_best_score <- .self$best_scores[i]
          .self$global_best <- .self$best_positions[i, ]
        }
      }
    },
    update_particles = function() {
      for (i in 1:.self$size) {
        for (j in 1:.self$dimensions) {
          r1 <- 0.5
          r2 <- 0.5
          cognitive <- r1 * (.self$best_positions[i, j] - .self$particles[i, j])
          social <- r2 * (.self$global_best[j] - .self$particles[i, j])
          .self$velocities[i, j] <- .self$velocities[i, j] + cognitive + social
          .self$particles[i, j] <- .self$particles[i, j] + .self$velocities[i, j]
        }
      }
    },
    evaluate = function(objective_function) {
      for (i in 1:.self$size) {
        score <- objective_function(.self$particles[i, ])
        if (score < .self$best_scores[i]) {
          .self$best_scores[i] <- score
          .self$best_positions[i, ] <- .self$particles[i, ]
        }
      }
      .self$update_global_best()
    }
  )
)

Optimization <- setRefClass("Optimization",
  fields = list(
    swarm = "Swarm",
    objective_function = "function"
  ),
  methods = list(
    initialize = function(swarm, objective_function) {
      .self$swarm <- swarm
      .self$objective_function <- objective_function
    },
    run = function() {
      while (TRUE) {
        .self$swarm$update_particles()
        .self$swarm$evaluate(.self$objective_function)
      }
    }
  )
)

objective_function <- function(position) {
  return(sum(position^2))
}

main <- function() {
  size <- 30
  dimensions <- 2
  swarm <- Swarm$new(size, dimensions)
  optimization <- Optimization$new(swarm, objective_function)
  optimization$run()
}

main()