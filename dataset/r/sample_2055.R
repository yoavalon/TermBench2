library(stats)

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
      return(.self)
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
      .self$particles <- lapply(1:num_particles, function(i) Particle$new(dimensions))
      .self$global_best_position <- rep(0.0, dimensions)
      .self$global_best_score <- Inf
      return(.self)
    },
    update_global_best = function() {
      for (particle in .self$particles) {
        score <- .self$evaluate(particle$position)
        if (score < .self$global_best_score) {
          .self$global_best_score <- score
          .self$global_best_position <- particle$position
        }
      }
    },
    evaluate = function(position) {
      return(sum(position^2))
    },
    update_particles = function(w, c1, c2) {
      for (particle in .self$particles) {
        for (i in 1:length(particle$position)) {
          r1 <- runif(1)
          r2 <- runif(1)
          particle$velocity[i] <- w * particle$velocity[i] + c1 * r1 * (particle$best_position[i] - particle$position[i]) + c2 * r2 * (.self$global_best_position[i] - particle$position[i])
          particle$position[i] <- particle$position[i] + particle$velocity[i]
          particle$best_score <- min(particle$best_score, .self$evaluate(particle$position))
          if (particle$best_score < .self$evaluate(particle$best_position)) {
            particle$best_position <- particle$position
          }
        }
      }
    }
  )
)

main <- function() {
  dimensions <- 30
  num_particles <- 30
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- 100
  swarm <- Swarm$new(num_particles, dimensions)
  for (i in 1:iterations) {
    swarm$update_global_best()
    swarm$update_particles(w, c1, c2)
  }
  cat('Best score:', swarm$global_best_score, '\n')
}

main()