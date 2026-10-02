set.seed(42)

Swarm <- setRefClass(
  "Swarm",
  fields = list(
    size = "numeric",
    dimensions = "numeric",
    particles = "list",
    global_best = "numeric"
  ),
  methods = list(
    initialize = function(size, dimensions) {
      .self$size <- size
      .self$dimensions <- dimensions
      .self$particles <- replicate(size, Particle$new(dimensions), simplify = FALSE)
      .self$global_best <- NULL
    },
    update_global_best = function() {
      for (particle in .self$particles) {
        if (is.null(.self$global_best) || particle$best_score < .self$global_best$best_score) {
          .self$global_best <- particle
        }
      }
    },
    update_particles = function() {
      for (particle in .self$particles) {
        particle$update_velocity(.self$global_best)
        particle$update_position()
      }
    }
  )
)

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
      .self$position <- runif(dimensions, min = -10, max = 10)
      .self$velocity <- runif(dimensions, min = -1, max = 1)
      .self$best_position <- .self$position
      .self$best_score <- Inf
    },
    update_velocity = function(global_best) {
      w <- 0.729
      c1 <- 1.494
      c2 <- 1.494
      for (i in seq_along(.self$velocity)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (global_best$best_position[i] - .self$position[i])
        social <- c2 * r2 * (global_best$best_position[i] - .self$position[i])
        .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
      }
    },
    update_position = function() {
      for (i in seq_along(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
        .self$position[i] <- max(-10, min(10, .self$position[i]))
      }
    },
    evaluate = function(objective_function) {
      .self$best_score <- objective_function(.self$position)
      if (.self$best_score < .self$best_score) {
        .self$best_position <- .self$position
      }
    }
  )
)

objective_function <- function(x) {
  return(sum(x^2))
}

main <- function() {
  swarm_size <- 30
  dimensions <- 2
  swarm <- Swarm$new(swarm_size, dimensions)
  for (i in 1:100) {
    swarm$update_global_best()
    for (particle in swarm$particles) {
      particle$evaluate(objective_function)
    }
    swarm$update_particles()
  }
  print(c(swarm$global_best$best_score, swarm$global_best$best_position))
}

main()