library(pracma)

Swarm <- setRefClass("Swarm",
  fields = list(
    size = "numeric",
    dimensions = "numeric",
    bounds = "numeric",
    particles = "list",
    gbest = "list"
  ),
  methods = list(
    initialize = function(size, dimensions, bounds) {
      .self$size <- size
      .self$dimensions <- dimensions
      .self$bounds <- bounds
      .self$particles <- lapply(1:size, function(i) new("Particle", dimensions, bounds))
      .self$gbest <- NULL
    },
    update_gbest = function() {
      for (particle in .self$particles) {
        if (is.null(.self$gbest) || particle$fitness < .self$gbest$fitness) {
          .self$gbest <<- particle
        }
      }
    },
    update_particles = function() {
      for (particle in .self$particles) {
        particle$update_velocity(.self$gbest)
        particle$update_position()
      }
    }
  )
)

Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric",
    fitness = "numeric"
  ),
  methods = list(
    initialize = function(dimensions, bounds) {
      .self$position <- runif(dimensions, bounds[1], bounds[2])
      .self$velocity <- runif(dimensions, -1, 1)
      .self$best_position <<- .self$position
      .self$fitness <<- Inf
    },
    update_velocity = function(gbest) {
      w <- 0.5
      c1 <- 1.5
      c2 <- 1.5
      for (i in 1:length(.self$velocity)) {
        r1 <- runif(1)
        r2 <- runif(1)
        cognitive <- c1 * r1 * (.self$best_position[i] - .self$position[i])
        social <- c2 * r2 * (gbest$position[i] - .self$position[i])
        .self$velocity[i] <<- w * .self$velocity[i] + cognitive + social
      }
    },
    update_position = function() {
      for (i in 1:length(.self$position)) {
        .self$position[i] <<- .self$position[i] + .self$velocity[i]
        if (.self$position[i] < .self$bounds[1]) {
          .self$position[i] <<- .self$bounds[1]
        }
        if (.self$position[i] > .self$bounds[2]) {
          .self$position[i] <<- .self$bounds[2]
        }
      }
    }
  )
)

objective_function <- function(x) {
  sum(x^2)
}

optimize <- function(swarm, max_iterations) {
  for (i in 1:max_iterations) {
    swarm$update_gbest()
    for (particle in swarm$particles) {
      particle$fitness <<- objective_function(particle$position)
    }
    swarm$update_particles()
  }
}

main <- function() {
  size <- 30
  dimensions <- 2
  bounds <- c(-10, 10)
  max_iterations <- 100
  swarm <- new("Swarm", size, dimensions, bounds)
  optimize(swarm, max_iterations)
  print(swarm$gbest$position)
}

main()