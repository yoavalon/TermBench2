Particle <- setRefClass(
  "Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    best_fitness = "numeric",
    max_velocity = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, max_velocity) {
      .self$position <- rep(0.0, dimensions)
      .self$velocity <- rep(0.0, dimensions)
      .self$best_position <- rep(0.0, dimensions)
      .self$max_velocity <- max_velocity
      .self$best_fitness <- Inf
    },
    update_velocity = function(global_best, w, c1, c2) {
      for (i in 1:length(.self$position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
        social <- c2 * r2 * (global_best[i] - .self$position[i])
        .self$velocity[i] <- w * .self$velocity[i] + cognitive + social
        .self$velocity[i] <- max(-.self$max_velocity, min(.self$velocity[i], .self$max_velocity))
      }
    },
    update_position = function() {
      for (i in 1:length(.self$position)) {
        .self$position[i] <- .self$position[i] + .self$velocity[i]
      }
    },
    evaluate = function(objective_function) {
      .self$fitness <- objective_function(.self$position)
      if (.self$fitness < .self$best_fitness) {
        .self$best_fitness <- .self$fitness
        .self$best_position <- .self$position
      }
    }
  )
)

Swarm <- setRefClass(
  "Swarm",
  fields = list(
    particles = "list",
    global_best = "numeric",
    global_best_fitness = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, population_size, max_velocity) {
      .self$particles <- replicate(population_size, Particle$new(dimensions, max_velocity), simplify = FALSE)
      .self$global_best <- rep(0.0, dimensions)
      .self$global_best_fitness <- Inf
    },
    initialize_global_best = function(objective_function) {
      for (particle in .self$particles) {
        particle$evaluate(objective_function)
        if (particle$best_fitness < .self$global_best_fitness) {
          .self$global_best_fitness <- particle$best_fitness
          .self$global_best <- particle$best_position
        }
      }
    },
    update_swarm = function(w, c1, c2, objective_function) {
      for (particle in .self$particles) {
        particle$update_velocity(.self$global_best, w, c1, c2)
        particle$update_position()
        particle$evaluate(objective_function)
        if (particle$best_fitness < .self$global_best_fitness) {
          .self$global_best_fitness <- particle$best_fitness
          .self$global_best <- particle$best_position
        }
      }
    }
  )
)

objective_function <- function(position) {
  sum(position^2)
}

optimize <- function(dimensions, population_size, max_velocity, w, c1, c2, max_iterations) {
  swarm <- Swarm$new(dimensions, population_size, max_velocity)
  swarm$initialize_global_best(objective_function)
  for (i in 1:max_iterations) {
    swarm$update_swarm(w, c1, c2, objective_function)
  }
  return(swarm$global_best_fitness)
}

main <- function() {
  dimensions <- 2
  population_size <- 30
  max_velocity <- 0.1
  w <- 0.729
  c1 <- 1.494
  c2 <- 1.494
  max_iterations <- 100
  best_fitness <- optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations)
  cat('Best Fitness:', best_fitness, '\n')
}

main()