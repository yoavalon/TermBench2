library(stats)

Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    best_fitness = "numeric"
  ),
  methods = list(
    initialize = function(dimensions) {
      .self$position <- runif(dimensions, -1, 1)
      .self$velocity <- runif(dimensions, -1, 1)
      .self$best_position <- .self$position
      .self$best_fitness <- Inf
    }
  )
)

PSO <- setRefClass("PSO",
  fields = list(
    dimensions = "numeric",
    population = "list",
    gbest_position = "numeric",
    gbest_fitness = "numeric",
    omega = "numeric",
    phi_p = "numeric",
    phi_g = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, population_size, omega, phi_p, phi_g) {
      .self$dimensions <- dimensions
      .self$population <- lapply(1:population_size, function(i) Particle$new(dimensions))
      .self$gbest_position <- rep(0, dimensions)
      .self$gbest_fitness <- Inf
      .self$omega <- omega
      .self$phi_p <- phi_p
      .self$phi_g <- phi_g
    },
    update_global_best = function() {
      for (particle in .self$population) {
        fitness <- .self$fitness(particle$position)
        if (fitness < particle$best_fitness) {
          particle$best_fitness <- fitness
          particle$best_position <- particle$position
        }
        if (fitness < .self$gbest_fitness) {
          .self$gbest_fitness <- fitness
          .self$gbest_position <- particle$position
        }
      }
    },
    update_velocity = function(particle) {
      for (i in 1:.self$dimensions) {
        r_p <- runif(1)
        r_g <- runif(1)
        cognitive <- .self$phi_p * r_p * (particle$best_position[i] - particle$position[i])
        social <- .self$phi_g * r_g * (.self$gbest_position[i] - particle$position[i])
        particle$velocity[i] <- .self$omega * particle$velocity[i] + cognitive + social
      }
    },
    update_position = function(particle) {
      for (i in 1:.self$dimensions) {
        particle$position[i] <- particle$position[i] + particle$velocity[i]
      }
    },
    fitness = function(position) {
      return(sum(position^2))
    },
    run = function() {
      while (TRUE) {
        .self$update_global_best()
        for (particle in .self$population) {
          .self$update_velocity(particle)
          .self$update_position(particle)
        }
      }
    }
  )
)

main <- function() {
  dimensions <- 2
  population_size <- 10
  omega <- 0.7
  phi_p <- 1.5
  phi_g <- 1.5
  pso <- PSO$new(dimensions, population_size, omega, phi_p, phi_g)
  pso$run()
}

main()