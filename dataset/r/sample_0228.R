library(stats)

set.seed(123)

Swarm <- function(size, dimensions, search_space) {
  self <- list(
    size = size,
    dimensions = dimensions,
    search_space = search_space,
    particles = replicate(size, Particle(dimensions, search_space), simplify = FALSE)
  )
  class(self) <- "Swarm"
  self
}

update <- function(swarm) {
  for (particle in swarm$particles) {
    particle$update_velocity()
    particle$update_position()
  }
}

Particle <- function(dimensions, search_space) {
  self <- list(
    dimensions = dimensions,
    search_space = search_space,
    position = sapply(1:dimensions, function(i) runif(1, search_space[1], search_space[2])),
    velocity = sapply(1:dimensions, function(i) runif(1, -1, 1)),
    best_position = self$position,
    best_fitness = Inf
  )
  class(self) <- "Particle"
  self
}

update_velocity <- function(particle) {
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  for (i in 1:particle$dimensions) {
    r1 <- runif(1)
    r2 <- runif(1)
    cognitive <- c1 * r1 * (particle$best_position[i] - particle$position[i])
    social <- c2 * r2 * (particle$best_position[i] - particle$position[i])
    particle$velocity[i] <- w * particle$velocity[i] + cognitive + social
  }
}

update_position <- function(particle) {
  for (i in 1:particle$dimensions) {
    particle$position[i] <- particle$position[i] + particle$velocity[i]
    particle$position[i] <- max(particle$search_space[1], min(particle$search_space[2], particle$position[i]))
  }
}

fitness_function <- function(position) {
  sum(position^2)
}

optimize <- function(swarm, max_iterations) {
  for (iteration in 1:max_iterations) {
    for (particle in swarm$particles) {
      current_fitness <- fitness_function(particle$position)
      if (current_fitness < particle$best_fitness) {
        particle$best_fitness <- current_fitness
        particle$best_position <- particle$position
      }
    }
    update(swarm)
  }
}

main <- function() {
  size <- 30
  dimensions <- 2
  search_space <- c(-10, 10)
  max_iterations <- 100
  swarm <- Swarm(size, dimensions, search_space)
  optimize(swarm, max_iterations)
}

main()