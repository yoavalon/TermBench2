library(stats)

Particle <- setRefClass("Particle",
  fields = list(position = "numeric", velocity = "numeric", best_position = "numeric", best_fitness = "numeric"),
  methods = list(
    initialize = function(dimensions) {
      .self$position <- runif(dimensions, -10, 10)
      .self$velocity <- runif(dimensions, -1, 1)
      .self$best_position <- .self$position
      .self$best_fitness <- Inf
      .self
    },
    update_velocity = function(global_best, w, c1, c2) {
      for (i in 1:length(.self$velocity)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
        social <- c2 * r2 * (global_best[i] - .self$position[i])
        .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
      }
    },
    update_position = function() {
      .self$position <- .self$position + .self$velocity
    },
    evaluate_fitness = function(fitness_function) {
      .self$best_fitness <- fitness_function(.self$position)
      if (.self$best_fitness < fitness_function(.self$best_position)) {
        .self$best_position <- .self$position
      }
    }
  )
)

Swarm <- setRefClass("Swarm",
  fields = list(particles = "list", global_best_position = "numeric", global_best_fitness = "numeric"),
  methods = list(
    initialize = function(dimensions, num_particles) {
      .self$particles <- lapply(1:num_particles, function(i) Particle$new(dimensions))
      .self$global_best_position <- NULL
      .self$global_best_fitness <- Inf
      .self
    },
    update_global_best = function(fitness_function) {
      for (particle in .self$particles) {
        particle$evaluate_fitness(fitness_function)
        if (particle$best_fitness < .self$global_best_fitness) {
          .self$global_best_fitness <- particle$best_fitness
          .self$global_best_position <- particle$best_position
        }
      }
    },
    optimize = function(fitness_function, w, c1, c2, iterations) {
      for (i in 1:iterations) {
        .self$update_global_best(fitness_function)
        for (particle in .self$particles) {
          particle$update_velocity(.self$global_best_position, w, c1, c2)
          particle$update_position()
        }
      }
    }
  )
)

sphere_function <- function(x) {
  sum(x^2)
}

main <- function() {
  dimensions <- 3
  num_particles <- 10
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- 100
  swarm <- Swarm$new(dimensions, num_particles)
  swarm$optimize(sphere_function, w, c1, c2, iterations)
  cat('Global Best Position:', swarm$global_best_position, '\n')
  cat('Global Best Fitness:', swarm$global_best_fitness, '\n')
}

main()