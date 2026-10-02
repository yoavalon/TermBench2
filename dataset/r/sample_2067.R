library(pracma)

Particle <- setRefClass("Particle",
  fields = list(
    position = "numeric",
    velocity = "numeric",
    best_pos = "numeric",
    best_score = "numeric"
  ),
  methods = list(
    initialize = function(dim) {
      position <<- rep(0.0, dim)
      velocity <<- rep(0.0, dim)
      best_pos <<- rep(0.0, dim)
      best_score <<- Inf
    },
    update_velocity = function(global_best, w, c1, c2) {
      for (i in 1:length(position)) {
        r1 <- runif(1)
        r2 <- runif(1)
        velocity[i] <<- w * velocity[i] + c1 * r1 * (best_pos[i] - position[i]) + c2 * r2 * (global_best[i] - position[i])
      }
    },
    update_position = function(bounds) {
      for (i in 1:length(position)) {
        position[i] <<- position[i] + velocity[i]
        position[i] <<- max(bounds[1, i], min(bounds[2, i], position[i]))
      }
    }
  )
)

Swarm <- setRefClass("Swarm",
  fields = list(
    particles = "list",
    best_global_pos = "numeric",
    best_global_score = "numeric"
  ),
  methods = list(
    initialize = function(num_particles, dim, bounds) {
      particles <<- lapply(1:num_particles, function(_) Particle$new(dim))
      best_global_pos <<- rep(0.0, dim)
      best_global_score <<- Inf
    },
    update_global_best = function() {
      for (particle in particles) {
        if (particle$best_score < best_global_score) {
          best_global_score <<- particle$best_score
          best_global_pos <<- particle$best_pos
        }
      }
    },
    optimize = function(fitness_func, max_iter, w, c1, c2) {
      for (iter in 1:max_iter) {
        for (particle in particles) {
          particle$update_velocity(best_global_pos, w, c1, c2)
          particle$update_position(bounds)
          score <- fitness_func(particle$position)
          if (score < particle$best_score) {
            particle$best_score <<- score
            particle$best_pos <<- particle$position
          }
        }
        update_global_best()
      }
    }
  )
)

fitness_function <- function(position) {
  return(sum(position^2))
}

main <- function() {
  num_particles <- 30
  dim <- 2
  bounds <- rbind(rep(0.0, dim), rep(10.0, dim))
  max_iter <- 100
  w <- 0.7
  c1 <- 2.0
  c2 <- 2.0
  swarm <- Swarm$new(num_particles, dim, bounds)
  swarm$optimize(fitness_function, max_iter, w, c1, c2)
  print(swarm$best_global_pos)
  print(swarm$best_global_score)
}

main()