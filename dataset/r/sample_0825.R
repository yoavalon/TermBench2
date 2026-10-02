r
Swarm <- setRefClass("Swarm",
  fields = list(
    particles = "list",
    best_position = "list"
  ),
  methods = list(
    initialize = function(size, dimensions) {
      .self$particles <- lapply(1:size, function(i) Particle$new(dimensions))
      .self$best_position <- NULL
    },
    update_best_position = function() {
      if (is.null(.self$best_position)) {
        .self$best_position <- .self$particles[[1]]$position
      } else {
        for (particle in .self$particles) {
          if (particle$fitness > .self$best_position$fitness) {
            .self$best_position <- particle$position
          }
        }
      }
    },
    update_particles = function(iterations) {
      if (iterations > 0) {
        for (particle in .self$particles) {
          particle$update_velocity(.self$best_position)
          particle$update_position()
        }
        .self$update_best_position()
        .self$update_particles(iterations - 1)
      }
    }
  )
)

Particle <- setRefClass("Particle",
  fields = list(
    position = "list",
    velocity = "list",
    fitness = "numeric"
  ),
  methods = list(
    initialize = function(dimensions) {
      .self$position <- rep(0.0, dimensions)
      .self$velocity <- rep(0.0, dimensions)
      .self$fitness <- 0.0
    },
    update_velocity = function(best_position) {
      w <- 0.7
      c1 <- 1.5
      c2 <- 1.5
      for (i in 1:length(.self$position)) {
        r1 <- 0.5
        r2 <- 0.5
        cognitive <- c1 * r1 * (best_position[i] - .self$position[i])
        social <- c2 * r2 * (best_position[i] - .self$position[i])
        .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
      }
    },
    update_position = function() {
      for (i in 1:length(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
      }
      .self$fitness <- .self$calculate_fitness()
    },
    calculate_fitness = function() {
      return(sum(.self$position^2))
    }
  )
)

optimize <- function(swarm, iterations) {
  swarm$update_particles(iterations)
}

main <- function() {
  dimensions <- 2
  swarm_size <- 10
  iterations <- 50
  swarm <- Swarm$new(swarm_size, dimensions)
  optimize(swarm, iterations)
}

main()