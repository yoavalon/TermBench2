library(stats)

Particle <- R6::R6Class("Particle",
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_fitness = NULL,
    
    initialize = function(dim, lb, ub) {
      self$position <- runif(dim, min = lb, max = ub)
      self$velocity <- runif(dim, min = -1, max = 1)
      self$best_position <- self$position
      self$best_fitness <- Inf
    },
    
    update_velocity = function(global_best, w, c1, c2) {
      for (i in seq_along(self$velocity)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (self$best_position[i] - self$position[i])
        social <- c2 * r2 * (global_best[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive + social
      }
    },
    
    update_position = function(lb, ub) {
      for (i in seq_along(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
        if (self$position[i] < lb) {
          self$position[i] <- lb
        }
        if (self$position[i] > ub) {
          self$position[i] <- ub
        }
      }
    }
  )
)

fitness_function <- function(x) {
  return(sum(x^2))
}

optimize <- function(dim, lb, ub, num_particles, w, c1, c2, max_iter) {
  particles <- lapply(1:num_particles, function(_) Particle$new(dim, lb, ub))
  global_best <- rep(Inf, dim)
  global_best_fitness <- Inf
  
  for (iter in 1:max_iter) {
    for (particle in particles) {
      current_fitness <- fitness_function(particle$position)
      if (current_fitness < particle$best_fitness) {
        particle$best_fitness <- current_fitness
        particle$best_position <- particle$position
      }
      if (current_fitness < global_best_fitness) {
        global_best_fitness <- current_fitness
        global_best <- particle$position
      }
    }
    
    for (particle in particles) {
      particle$update_velocity(global_best, w, c1, c2)
      particle$update_position(lb, ub)
    }
  }
  
  return(list(global_best, global_best_fitness))
}

main <- function() {
  dim <- 30
  lb <- -100
  ub <- 100
  num_particles <- 50
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  max_iter <- 10000
  
  best_position <- optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter)[[1]]
  best_fitness <- optimize(dim, lb, ub, num_particles, w, c1, c2, max_iter)[[2]]
  
  cat("Best position:", paste(best_position, collapse = ", "), "\n")
  cat("Best fitness:", best_fitness, "\n")
}

main()