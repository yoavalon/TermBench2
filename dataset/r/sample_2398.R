library(stats)

Particle <- R6::R6Class("Particle", 
  public = list(
    position = NULL,
    velocity = NULL,
    best_position = NULL,
    best_fitness = Inf,
    initialize = function(dimensions, lower_bound, upper_bound) {
      self$position <- runif(dimensions, lower_bound, upper_bound)
      self$velocity <- runif(dimensions, -1, 1)
      self$best_position <- self$position
      self$best_fitness <- Inf
    },
    update_velocity = function(global_best_position, w, c1, c2) {
      for (i in seq_along(self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive_velocity <- c1 * r1 * (self$best_position[i] - self$position[i])
        social_velocity <- c2 * r2 * (global_best_position[i] - self$position[i])
        self$velocity[i] <- w * self$velocity[i] + cognitive_velocity + social_velocity
      }
    },
    update_position = function(lower_bound, upper_bound) {
      for (i in seq_along(self$position)) {
        self$position[i] <- self$position[i] + self$velocity[i]
        self$position[i] <- pmax(lower_bound, pmin(upper_bound, self$position[i]))
      }
    }
  )
)

Swarm <- R6::R6Class("Swarm", 
  public = list(
    particles = NULL,
    global_best_position = NULL,
    global_best_fitness = Inf,
    initialize = function(num_particles, dimensions, lower_bound, upper_bound) {
      self$particles <- purrr::map(1:num_particles, ~Particle$new(dimensions, lower_bound, upper_bound))
      self$global_best_position <- runif(dimensions, lower_bound, upper_bound)
      self$global_best_fitness <- Inf
    },
    evaluate_fitness = function(objective_function) {
      for (particle in self$particles) {
        fitness <- objective_function(particle$position)
        if (fitness < particle$best_fitness) {
          particle$best_fitness <- fitness
          particle$best_position <- particle$position
        }
        if (fitness < self$global_best_fitness) {
          self$global_best_fitness <- fitness
          self$global_best_position <- particle$position
        }
      }
    },
    update_particles = function(w, c1, c2) {
      for (particle in self$particles) {
        particle$update_velocity(self$global_best_position, w, c1, c2)
        particle$update_position(-10, 10)
      }
    }
  )
)

objective_function <- function(x) {
  sum(sin(x) * sin(x + (seq_along(x) + 1) * pi / length(x)))
}

main <- function() {
  num_particles <- 30
  dimensions <- 30
  lower_bound <- -10
  upper_bound <- 10
  w <- 0.729
  c1 <- 1.494
  c2 <- 1.494
  swarm <- Swarm$new(num_particles, dimensions, lower_bound, upper_bound)
  while (TRUE) {
    swarm$evaluate_fitness(objective_function)
    swarm$update_particles(w, c1, c2)
  }
}

main()