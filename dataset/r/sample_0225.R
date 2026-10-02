PSOSettings <- setRefClass("PSOSettings",
  fields = list(
    dimensions = "numeric",
    population_size = "numeric",
    max_iterations = "numeric",
    c1 = "numeric",
    c2 = "numeric",
    w = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, population_size, max_iterations) {
      .self$dimensions <- dimensions
      .self$population_size <- population_size
      .self$max_iterations <- max_iterations
      .self$c1 <- 2.0
      .self$c2 <- 2.0
      .self$w <- 0.7
    }
  )
)

Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    best_fitness = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, lower_bound, upper_bound) {
      .self$position <- runif(dimensions, lower_bound, upper_bound)
      .self$velocity <- runif(dimensions, -1, 1)
      .self$best_position <- .self$position
      .self$best_fitness <- Inf
    }
  )
)

fitness <- function(position) {
  sum(position^2)
}

update_velocity <- function(particle, global_best, settings) {
  for (i in 1:settings$dimensions) {
    r1 <- runif(1)
    r2 <- runif(1)
    cognitive <- settings$c1 * r1 * (particle$best_position[i] - particle$position[i])
    social <- settings$c2 * r2 * (global_best[i] - particle$position[i])
    particle$velocity[i] <- settings$w * particle$velocity[i] + cognitive + social
  }
}

update_position <- function(particle, settings) {
  for (i in 1:settings$dimensions) {
    particle$position[i] <- particle$position[i] + particle$velocity[i]
    if (particle$position[i] < -10) {
      particle$position[i] <- -10
    } else if (particle$position[i] > 10) {
      particle$position[i] <- 10
    }
  }
}

optimize <- function(settings) {
  population <- lapply(1:settings$population_size, function(i) {
    Particle$new(settings$dimensions, -10, 10)
  })
  global_best <- rep(0, settings$dimensions)
  global_best_fitness <- Inf
  for (iteration in 1:settings$max_iterations) {
    for (particle in population) {
      current_fitness <- fitness(particle$position)
      if (current_fitness < particle$best_fitness) {
        particle$best_fitness <- current_fitness
        particle$best_position <- particle$position
      }
      if (current_fitness < global_best_fitness) {
        global_best_fitness <- current_fitness
        global_best <- particle$position
      }
    }
    for (particle in population) {
      update_velocity(particle, global_best, settings)
      update_position(particle, settings)
    }
  }
  return(list(global_best, global_best_fitness))
}

main <- function() {
  settings <- PSOSettings$new(dimensions = 2, population_size = 30, max_iterations = 100)
  best_position <- optimize(settings)[[1]]
  best_fitness <- optimize(settings)[[2]]
  print(paste("Best position:", best_position))
  print(paste("Best fitness:", best_fitness))
}

main()