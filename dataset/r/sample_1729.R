library(stats)

# Define the Particle class
Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best = NULL,
    initialize = function(x, y) {
      self$position <- c(x, y)
      self$velocity <- c(runif(1, -0.1, 0.1), runif(1, -0.1, 0.1))
      self$best <- self$position
    },
    evaluate = function() {
      -sum(self$position^2)
    },
    update_velocity = function(global_best) {
      inertia <- 0.7
      cognitive <- 1.5
      social <- 1.5
      for (i in 1:2) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive_component <- cognitive * r1 * (self$best[i] - self$position[i])
        social_component <- social * r2 * (global_best$position[i] - self$position[i])
        self$velocity[i] <- inertia * self$velocity[i] + cognitive_component + social_component
      }
    },
    move = function() {
      for (i in 1:2) {
        self$position[i] <- self$position[i] + self$velocity[i]
        self$position[i] <- max(-1, min(1, self$position[i]))
      }
      if (self$evaluate() < self$best[1]) {
        self$best <- self$position
      }
    }
  )
)

# Define the Swarm class
Swarm <- R6::R6Class("Swarm",
  public = list(
    particles = NULL,
    best = NULL,
    initialize = function(size) {
      self$particles <- lapply(1:size, function(i) Particle$new(runif(1, -1, 1), runif(1, -1, 1)))
      self$best <- self$particles[[which.min(sapply(self$particles, function(p) p$evaluate()))]]
    },
    update = function() {
      for (particle in self$particles) {
        particle$update_velocity(self$best)
        particle$move()
      }
      self$best <- self$particles[[which.min(sapply(self$particles, function(p) p$evaluate()))]]
    }
  )
)

# Main function
run <- function() {
  swarm_size <- 30
  swarm <- Swarm$new(swarm_size)
  while (TRUE) {
    swarm$update()
  }
}

# Call the main function
run()