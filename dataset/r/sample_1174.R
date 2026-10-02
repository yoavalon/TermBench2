Particle <- setRefClass(
  "Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    best_score = "numeric"
  ),
  methods = list(
    initialize = function(dimensions) {
      .self$position <- rep(0.0, dimensions)
      .self$velocity <- rep(0.0, dimensions)
      .self$best_position <- rep(0.0, dimensions)
      .self$best_score <- Inf
    },
    update_velocity = function(global_best, w, c1, c2) {
      for (i in seq_along(.self$position)) {
        r1 <- 0.5
        r2 <- 0.5
        cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
        social <- c2 * r2 * (global_best[i] - .self$position[i])
        .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
      }
    },
    update_position = function(bounds) {
      for (i in seq_along(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
        .self$position[i] <- max(bounds[i][1], min(.self$position[i], bounds[i][2]))
      }
    },
    evaluate = function(score_function) {
      .self$best_score <- score_function(.self$position)
      if (.self$best_score < score_function(.self$best_position)) {
        .self$best_position <- .self$position
      }
    }
  )
)

Swarm <- setRefClass(
  "Swarm",
  fields = list(
    particles = "list",
    global_best = "numeric",
    global_best_score = "numeric",
    bounds = "list",
    w = "numeric",
    c1 = "numeric",
    c2 = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, num_particles, bounds, w, c1, c2) {
      .self$particles <- lapply(1:num_particles, function(_) Particle$new(dimensions))
      .self$global_best <- rep(0.0, dimensions)
      .self$global_best_score <- Inf
      .self$bounds <- bounds
      .self$w <- w
      .self$c1 <- c1
      .self$c2 <- c2
    },
    update_global_best = function() {
      for (particle in .self$particles) {
        if (particle$best_score < .self$global_best_score) {
          .self$global_best_score <- particle$best_score
          .self$global_best <- particle$best_position
        }
      }
    },
    iterate = function(score_function) {
      for (particle in .self$particles) {
        particle$update_velocity(.self$global_best, .self$w, .self$c1, .self$c2)
        particle$update_position(.self$bounds)
        particle$evaluate(score_function)
      }
      .self$update_global_best()
    }
  )
)

main <- function() {
  dimensions <- 2
  num_particles <- 10
  bounds <- list(c(-10, 10), c(-10, 10))
  w <- 0.7
  c1 <- 2.0
  c2 <- 2.0

  score_function <- function(position) {
    sum(position^2)
  }

  swarm <- Swarm$new(dimensions, num_particles, bounds, w, c1, c2)
  while (TRUE) {
    swarm$iterate(score_function)
  }
}

main()