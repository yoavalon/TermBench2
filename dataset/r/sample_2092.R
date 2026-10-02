r
library(stats)

Particle <- setRefClass("Particle",
                      fields = list(position = "numeric", 
                                    velocity = "numeric", 
                                    best_position = "numeric", 
                                    best_score = "numeric"),
                      methods = list(
                        initialize = function(dimensions) {
                          .self$position <- runif(dimensions, -10, 10)
                          .self$velocity <- runif(dimensions, -1, 1)
                          .self$best_position <- .self$position
                          .self$best_score <- Inf
                        }
                      )
)

Swarm <- setRefClass("Swarm",
                    fields = list(particles = "list", 
                                  gbest_position = "numeric", 
                                  gbest_score = "numeric"),
                    methods = list(
                      initialize = function(num_particles, dimensions) {
                        .self$particles <- replicate(num_particles, Particle$new(dimensions), simplify = FALSE)
                        .self$gbest_position <- NULL
                        .self$gbest_score <- Inf
                      },
                      update_gbest = function() {
                        for (particle in .self$particles) {
                          if (particle$best_score < .self$gbest_score) {
                            .self$gbest_score <<- particle$best_score
                            .self$gbest_position <<- particle$best_position
                          }
                        }
                      },
                      update_particles = function(w, c1, c2) {
                        for (particle in .self$particles) {
                          for (i in seq_along(particle$position)) {
                            r1 <- runif(1)
                            r2 <- runif(1)
                            particle$velocity[i] <- w * particle$velocity[i] + c1 * r1 * (particle$best_position[i] - particle$position[i]) + c2 * r2 * (.self$gbest_position[i] - particle$position[i])
                            particle$position[i] <- particle$position[i] + particle$velocity[i]
                          }
                        }
                      },
                      evaluate = function(objective_function) {
                        for (particle in .self$particles) {
                          score <- objective_function(particle$position)
                          if (score < particle$best_score) {
                            particle$best_score <<- score
                            particle$best_position <<- particle$position
                          }
                        }
                      }
                    )
)

objective_function <- function(x) {
  sum(x^2)
}

main <- function() {
  dimensions <- 3
  num_particles <- 20
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- 100
  swarm <- Swarm$new(num_particles, dimensions)
  for (i in 1:iterations) {
    swarm$update_gbest()
    swarm$update_particles(w, c1, c2)
    swarm$evaluate(objective_function)
  }
  cat('Best score:', swarm$gbest_score, '\n')
  cat('Best position:', swarm$gbest_position, '\n')
}

main()