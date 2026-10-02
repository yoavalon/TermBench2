r
library(pracma)

initialize_particles <- function(num_particles, dimensions, bounds) {
  particles <- matrix(runif(num_particles * dimensions, bounds[1], bounds[2]), nrow = num_particles, ncol = dimensions)
  return(particles)
}

update_positions <- function(particles, velocities, bounds) {
  new_positions <- particles + velocities
  new_positions[new_positions < bounds[1]] <- bounds[1]
  new_positions[new_positions > bounds[2]] <- bounds[2]
  return(new_positions)
}

main <- function() {
  num_particles <- 30
  dimensions <- 2
  bounds <- c(0, 10)
  particles <- initialize_particles(num_particles, dimensions, bounds)
  velocities <- matrix(runif(num_particles * dimensions, -1, 1), nrow = num_particles, ncol = dimensions)
  for (i in 1:100) {
    particles <- update_positions(particles, velocities, bounds)
  }
  print(particles)
}

main()