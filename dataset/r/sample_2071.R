library(stats)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_pos = NULL,
    best_score = Inf,
    initialize = function(dim, bounds) {
      self$position <- sapply(bounds, function(b) runif(1, min = b[1], max = b[2]))
      self$velocity <- runif(dim, min = -1, max = 1)
      self$best_pos <- self$position
      self$best_score <- Inf
    },
    update_velocity = function(global_best, w = 0.7, c1 = 1.5, c2 = 1.5) {
      for (i in 1:length(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (self$best_pos[i] - self$position[i])
        social <- c2 * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive + social
      }
    },
    update_position = function(bounds) {
      for (i in 1:length(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
        self$position[i] <- pmax(bounds[i][1], pmin(self$position[i], bounds[i][2]))
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    global_best = NULL,
    global_best_score = Inf,
    initialize = function(dim, num_particles, bounds) {
      self$particles <- lapply(1:num_particles, function(_) Particle$new(dim, bounds))
      self$global_best <- rep(Inf, dim)
      self$global_best_score <- Inf
    },
    update_global_best = function() {
      for (particle in self$particles) {
        score <- self$evaluate(particle$position)
        if (score < self$global_best_score) {
          self$global_best <- particle$position
          self$global_best_score <- score
          particle$best_score <- score
          particle$best_pos <- particle$position
        }
      }
    },
    evaluate = function(position) {
      sum(position^2)
    },
    run = function(iterations) {
      for (i in 1:iterations) {
        for (particle in self$particles) {
          particle$update_velocity(self$global_best)
          particle$update_position(bounds)
        }
        self$update_global_best()
      }
    }
  )
)

main <- function() {
  dim <- 3
  num_particles <- 20
  bounds <- list(rep(c(-10, 10), dim))
  swarm <- Swarm$new(dim, num_particles, bounds)
  swarm$run(100)
  cat('Global Best Position:', swarm$global_best, '\n')
  cat('Global Best Score:', swarm$global_best_score, '\n')
}

main()