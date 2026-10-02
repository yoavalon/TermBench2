Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_position = "numeric"
  ),
  methods = list(
    update_velocity = function(global_best, w, c1, c2) {
      r1 <- 0.5
      r2 <- 0.3
      new_velocity <- w * self$velocity + c1 * r1 * (self$best_position - self$position) + c2 * r2 * (global_best - self$position)
      self$velocity <<- new_velocity
    },
    update_position = function() {
      self$position <<- self$position + self$velocity
      if (self$position < self$best_position) {
        self$best_position <<- self$position
      }
    }
  )
)

update_global_best <- function(particles) {
  best <- particles[[1]]$best_position
  for (particle in particles) {
    if (particle$best_position < best) {
      best <- particle$best_position
    }
  }
  return(best)
}

optimize <- function(particles, global_best, w, c1, c2, iterations) {
  if (iterations == 0) {
    return(global_best)
  }
  for (particle in particles) {
    particle$update_velocity(global_best, w, c1, c2)
    particle$update_position()
  }
  new_global_best <- update_global_best(particles)
  return(optimize(particles, new_global_best, w, c1, c2, iterations - 1))
}

main <- function() {
  num_particles <- 10
  initial_positions <- rep(0.0, num_particles)
  initial_velocities <- rep(0.1, num_particles)
  best_positions <- rep(0.0, num_particles)
  particles <- lapply(seq_len(num_particles), function(i) {
    Particle$new(position = initial_positions[i], velocity = initial_velocities[i], best_position = best_positions[i])
  })
  global_best <- update_global_best(particles)
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- Inf
  optimize(particles, global_best, w, c1, c2, iterations)
}

main()