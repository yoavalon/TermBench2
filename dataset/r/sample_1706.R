library(pracma)

Particle <- setRefClass("Particle",
                        fields = list(
                          position = "numeric",
                          velocity = "numeric",
                          best_position = "numeric",
                          best_fitness = "numeric"
                        ),
                        methods = list(
                          initialize = function(dim) {
                            .self$position <- runif(dim, -10, 10)
                            .self$velocity <- runif(dim, -1, 1)
                            .self$best_position <- .self$position
                            .self$best_fitness <- Inf
                          },
                          update_velocity = function(global_best, w = 0.5, c1 = 1.5, c2 = 1.5) {
                            for (i in 1:length(.self$position)) {
                              r1 <- runif(1)
                              r2 <- runif(1)
                              cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
                              social <- c2 * r2 * (global_best[i] - .self$position[i])
                              .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
                            }
                          },
                          update_position = function() {
                            for (i in 1:length(.self$position)) {
                              .self$position[i] <- .self$position[i] + .self$velocity[i]
                            }
                          }
                        )
)

Swarm <- setRefClass("Swarm",
                      fields = list(
                        particles = "list",
                        global_best_position = "numeric",
                        global_best_fitness = "numeric"
                      ),
                      methods = list(
                        initialize = function(dim, num_particles) {
                          .self$particles <- lapply(1:num_particles, function(_) Particle$new(dim))
                          .self$global_best_position <- rep(Inf, dim)
                          .self$global_best_fitness <- Inf
                        },
                        update_global_best = function() {
                          for (particle in .self$particles) {
                            fitness <- .self$evaluate(particle$position)
                            if (fitness < particle$best_fitness) {
                              particle$best_fitness <<- fitness
                              particle$best_position <<- particle$position
                            }
                            if (fitness < .self$global_best_fitness) {
                              .self$global_best_fitness <<- fitness
                              .self$global_best_position <<- particle$position
                            }
                          }
                        },
                        evaluate = function(position) {
                          sum(position^2)
                        },
                        iterate = function() {
                          .self$update_global_best()
                          for (particle in .self$particles) {
                            particle$update_velocity(.self$global_best_position)
                            particle$update_position()
                          }
                        }
                      )
)

main <- function() {
  dim <- 2
  num_particles <- 10
  swarm <- Swarm$new(dim, num_particles)
  while (TRUE) {
    swarm$iterate()
  }
}

main()