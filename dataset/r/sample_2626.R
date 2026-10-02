library(stats)

set.seed(123)

Particle <- setRefClass("Particle",
                      fields = list(
                        position = "numeric",
                        velocity = "numeric",
                        best_position = "numeric",
                        best_score = "numeric"
                      ),
                      methods = list(
                        initialize = function(dimensions, position = NULL) {
                          .self$position <- if (!is.null(position)) position else runif(dimensions, -1, 1)
                          .self$velocity <- runif(dimensions, -1, 1)
                          .self$best_position <- .self$position
                          .self$best_score <- Inf
                        },
                        
                        update_velocity = function(global_best, w = 0.7, c1 = 1.5, c2 = 1.5) {
                          for (i in seq_along(.self$position)) {
                            r1 <- runif(1)
                            r2 <- runif(1)
                            cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
                            social <- c2 * r2 * (global_best[i] - .self$position[i])
                            .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
                          }
                        },
                        
                        update_position = function(bounds) {
                          for (i in seq_along(.self$position)) {
                            .self$position[i] <- .self$position[i] + .self$velocity[i]
                            if (!is.null(bounds)) {
                              .self$position[i] <- pmax(bounds[1], pmin(bounds[2], .self$position[i]))
                            }
                          }
                        },
                        
                        evaluate = function(function) {
                          .self$current_score <- do.call(function, list(.self$position))
                          if (.self$current_score < .self$best_score) {
                            .self$best_score <- .self$current_score
                            .self$best_position <- .self$position
                          }
                        }
                      ))

Swarm <- setRefClass("Swarm",
                    fields = list(
                      particles = "list",
                      global_best = "numeric",
                      global_best_score = "numeric",
                      bounds = "numeric"
                    ),
                    methods = list(
                      initialize = function(dimensions, num_particles, bounds = NULL) {
                        .self$particles <- lapply(1:num_particles, function(i) Particle$new(dimensions))
                        .self$global_best <- NULL
                        .self$global_best_score <- Inf
                        .self$bounds <- bounds
                      },
                      
                      update_global_best = function() {
                        for (particle in .self$particles) {
                          if (particle$best_score < .self$global_best_score) {
                            .self$global_best_score <- particle$best_score
                            .self$global_best <- particle$best_position
                          }
                        }
                      },
                      
                      optimize = function(function, iterations) {
                        for (i in 1:iterations) {
                          .self$update_global_best()
                          for (particle in .self$particles) {
                            particle$update_velocity(.self$global_best)
                            particle$update_position(.self$bounds)
                            particle$evaluate(function)
                          }
                        }
                      }
                    ))

objective_function <- function(x) {
  sum(x^2)
}

main <- function() {
  dimensions <- 2
  num_particles <- 30
  bounds <- c(-10, 10)
  iterations <- 100
  swarm <- Swarm$new(dimensions, num_particles, bounds)
  swarm$optimize(objective_function, iterations)
  cat('Global Best Position:', swarm$global_best, '\n')
  cat('Global Best Score:', swarm$global_best_score, '\n')
}

main()