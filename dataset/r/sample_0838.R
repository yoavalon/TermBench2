Swarm <- setRefClass("Swarm",
  fields = list(
    size = "numeric",
    dimensions = "numeric",
    bounds = "list",
    positions = "list",
    velocities = "list",
    pbest_positions = "list",
    pbest_scores = "numeric",
    gbest_position = "numeric",
    gbest_score = "numeric"
  ),
  methods = list(
    initialize = function(size, dimensions, bounds) {
      .self$size <- size
      .self$dimensions <- dimensions
      .self$bounds <- bounds
      .self$positions <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
      .self$velocities <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
      .self$pbest_positions <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
      .self$pbest_scores <- rep(Inf, size)
      .self$gbest_position <- rep(0.0, dimensions)
      .self$gbest_score <- Inf
    },
    initialize = function() {
      for (i in 1:.self$size) {
        for (j in 1:.self$dimensions) {
          .self$positions[[i]][j] <- (bounds[[j]][2] - bounds[[j]][1]) * runif(1) + bounds[[j]][1]
          .self$velocities[[i]][j] <- (bounds[[j]][2] - bounds[[j]][1]) * runif(1) - (bounds[[j]][2] - bounds[[j]][1]) / 2
        }
      }
    },
    evaluate = function(function) {
      for (i in 1:.self$size) {
        score <- do.call(function, list(.self$positions[[i]]))
        if (score < .self$pbest_scores[i]) {
          .self$pbest_scores[i] <- score
          .self$pbest_positions[[i]] <- .self$positions[[i]]
        }
        if (score < .self$gbest_score) {
          .self$gbest_score <- score
          .self$gbest_position <- .self$positions[[i]]
        }
      }
    },
    update_velocities = function(w, c1, c2) {
      for (i in 1:.self$size) {
        for (j in 1:.self$dimensions) {
          .self$velocities[[i]][j] <- w * .self$velocities[[i]][j] + c1 * runif(1) * (.self$pbest_positions[[i]][j] - .self$positions[[i]][j]) + c2 * runif(1) * (.self$gbest_position[j] - .self$positions[[i]][j])
        }
      }
    },
    update_positions = function() {
      for (i in 1:.self$size) {
        for (j in 1:.self$dimensions) {
          .self$positions[[i]][j] <- .self$positions[[i]][j] + .self$velocities[[i]][j]
          .self$positions[[i]][j] <- max(bounds[[j]][1], min(bounds[[j]][2], .self$positions[[i]][j]))
        }
      }
    },
    optimize = function(function, iterations) {
      .self$initialize()
      for (i in 1:iterations) {
        .self$evaluate(function)
        .self$update_velocities(0.7, 1.5, 1.5)
        .self$update_positions()
      }
      return(.self$gbest_score)
    }
  )
)

objective <- function(x) {
  return(sum((x - 0.5) ^ 2))
}

main <- function() {
  dimensions <- 3
  bounds <- list(c(-10, 10), c(-10, 10), c(-10, 10))
  swarm_size <- 30
  iterations <- 100
  swarm <- Swarm$new(swarm_size, dimensions, bounds)
  best_score <- swarm$optimize(objective, iterations)
  print(best_score)
}

main()