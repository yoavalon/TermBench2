r
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
                        initialize = function(dimensions) {
                          .self$position <- runif(dimensions, -10, 10)
                          .self$velocity <- runif(dimensions, -1, 1)
                          .self$best_position <- .self$position
                          .self$best_score <- Inf
                        },
                        update_velocity = function(global_best_position, w, c1, c2) {
                          for (i in 1:length(.self$velocity)) {
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
                            if (.self$position[i] < -10) {
                              .self$position[i] <- -10
                            } else if (.self$position[i] > 10) {
                              .self$position[i] <- 10
                            }
                          }
                        },
                        evaluate = function(objective_function) {
                          score <- objective_function(.self$position)
                          if (score < .self$best_score) {
                            .self$best_score <- score
                            .self$best_position <- .self$position
                          }
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
                        .self$particles <- lapply(1:num_particles, function(_) Particle$new(dimensions))
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
                      },
                      optimize = function(objective_function, w, c1, c2, iterations) {
                        for (i in 1:iterations) {
                          for (particle in .self$particles) {
                            particle$update_velocity(.self$global_best_position, w, c1, c2)
                            particle$update_position()
                            particle$evaluate(objective_function)
                          }
                          .self$update_global_best()
                        }
                      }
                    )
)

objective_function <- function(x) {
  return(sum(x^2))
}

main <- function() {
  dimensions <- 3
  num_particles <- 10
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- 50
  swarm <- Swarm$new(num_particles, dimensions)
  swarm$optimize(objective_function, w, c1, c2, iterations)
  print(paste("Best position:", paste(swarm$global_best_position, collapse = ", ")))
  print(paste("Best score:", swarm$global_best_score))
}

main()