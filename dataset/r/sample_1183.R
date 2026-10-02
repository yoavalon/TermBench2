Swarm <- R6::R6Class("Swarm",
  public = list(
    size = NULL,
    dimensions = NULL,
    positions = NULL,
    velocities = NULL,
    best_positions = NULL,
    best_scores = NULL,
    global_best_position = NULL,
    global_best_score = NULL,
    
    initialize = function(size, dimensions) {
      self$size <- size
      self$dimensions <- dimensions
      self$positions <- matrix(0.0, nrow = size, ncol = dimensions)
      self$velocities <- matrix(0.0, nrow = size, ncol = dimensions)
      self$best_positions <- matrix(0.0, nrow = size, ncol = dimensions)
      self$best_scores <- rep(Inf, size)
      self$global_best_position <- rep(0.0, dimensions)
      self$global_best_score <- Inf
    },
    
    update_global_best = function() {
      for (i in 1:self$size) {
        score <- self$evaluate(self$best_positions[i, ])
        if (score < self$global_best_score) {
          self$global_best_score <- score
          self$global_best_position <- self$best_positions[i, ]
        }
      }
    },
    
    evaluate = function(position) {
      sum(position ^ 2)
    },
    
    update_particles = function() {
      for (i in 1:self$size) {
        for (j in 1:self$dimensions) {
          r1 <- 0.5
          r2 <- 0.5
          c1 <- 2.0
          c2 <- 2.0
          self$velocities[i, j] <- 0.7 * self$velocities[i, j] + c1 * r1 * (self$best_positions[i, j] - self$positions[i, j]) + c2 * r2 * (self$global_best_position[j] - self$positions[i, j])
          self$positions[i, j] <- self$positions[i, j] + self$velocities[i, j]
        }
        self$best_scores[i] <- self$evaluate(self$positions[i, ])
        if (self$best_scores[i] < self$global_best_score) {
          self$best_positions[i, ] <- self$positions[i, ]
        }
      }
    },
    
    iterate = function() {
      self$update_global_best()
      self$update_particles()
      self$iterate()
    }
  )
)

main <- function() {
  swarm <- Swarm$new(30, 2)
  swarm$iterate()
}

main()