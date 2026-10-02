Swarm <- setRefClass("Swarm",
  fields = list(
    particles = "list",
    best = "Particle"
  ),
  methods = list(
    initialize = function(size, dimensions) {
      .self$particles <- lapply(1:size, function(i) Particle(dimensions = dimensions))
      .self$best <- .self$particles[[1]]
    },
    update_best = function() {
      for (particle in .self$particles) {
        if (particle$position < .self$best$position) {
          .self$best <- particle
        }
      }
    },
    update_positions = function() {
      for (particle in .self$particles) {
        particle$update_velocity(best_swarm = .self$best)
        particle$move()
      }
    }
  )
)

Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best = "numeric"
  ),
  methods = list(
    initialize = function(dimensions) {
      .self$position <- rep(0.0, dimensions)
      .self$velocity <- rep(0.0, dimensions)
      .self$best <- .self$position
    },
    update_velocity = function(best_swarm) {
      for (i in 1:length(.self$position)) {
        c1 <- 1.5
        c2 <- 1.5
        r1 <- 0.5
        r2 <- 0.5
        .self$velocity[i] <- 0.7 * .self$velocity[i] + c1 * r1 * (best_swarm$position[i] - .self$position[i]) + c2 * r2 * (.self$best[i] - .self$position[i])
      }
    },
    move = function() {
      for (i in 1:length(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
      }
      if (all(.self$position < .self$best)) {
        .self$best <- .self$position
      }
    }
  )
)

optimize <- function(swarm) {
  swarm$update_positions()
  swarm$update_best()
  optimize(swarm)
}

main <- function() {
  swarm <- Swarm(size = 10, dimensions = 2)
  optimize(swarm)
}

main()