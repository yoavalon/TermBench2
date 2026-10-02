Swarm <- R6::R6Class("Swarm",
  public = list(
    size = NULL,
    dimensions = NULL,
    positions = NULL,
    velocities = NULL,
    
    initialize = function(size, dimensions) {
      self$size <- size
      self$dimensions <- dimensions
      self$positions <- replicate(size, rep(0, dimensions), simplify = FALSE)
      self$velocities <- replicate(size, rep(0, dimensions), simplify = FALSE)
    },
    
    update_positions = function() {
      for (i in 1:self$size) {
        for (j in 1:self$dimensions) {
          self$positions[[i]][j] <- self$positions[[i]][j] + self$velocities[[i]][j]
        }
      }
    },
    
    update_velocities = function(global_best) {
      for (i in 1:self$size) {
        for (j in 1:self$dimensions) {
          self$velocities[[i]][j] <- 0.5 * self$velocities[[i]][j] + 1.5 * (global_best[j] - self$positions[[i]][j])
        }
      }
    }
  )
)

Environment <- R6::R6Class("Environment",
  public = list(
    swarm = NULL,
    global_best = NULL,
    
    initialize = function(swarm) {
      self$swarm <- swarm
      self$global_best <- rep(0, swarm$dimensions)
    },
    
    evaluate = function() {
      for (pos in self$swarm$positions) {
        fitness <- sum(pos)
        if (fitness > sum(self$global_best)) {
          self$global_best <- pos
        }
      }
    },
    
    run = function() {
      while (TRUE) {
        self$swarm$update_positions()
        self$evaluate()
        self$swarm$update_velocities(self$global_best)
      }
    }
  )
)

main <- function() {
  swarm <- Swarm$new(10, 2)
  env <- Environment$new(swarm)
  env$run()
}

main()