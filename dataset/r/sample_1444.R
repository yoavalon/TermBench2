r
library(stats)

Particle <- setRefClass("Particle",
  fields = list(position = "numeric", velocity = "numeric", best_position = "numeric", best_score = "numeric"),
  methods = list(
    initialize = function(dimensions, bounds) {
      position <<- runif(dimensions, bounds[1], bounds[2])
      velocity <<- runif(dimensions, -1, 1)
      best_position <<- position
      best_score <<- Inf
    },
    update_velocity = function(global_best, w = 0.7, c1 = 1.5, c2 = 1.5) {
      for (i in 1:length(velocity)) {
        r1 <<- runif(1)
        r2 <<- runif(1)
        velocity[i] <<- w * velocity[i] + c1 * r1 * (best_position[i] - position[i]) + c2 * r2 * (global_best[i] - position[i])
      }
    },
    update_position = function(bounds) {
      for (i in 1:length(position)) {
        position[i] <<- position[i] + velocity[i]
        position[i] <<- max(bounds[1], min(bounds[2], position[i]))
      }
    },
    evaluate = function(objective_function) {
      score <<- objective_function(position)
      if (score < best_score) {
        best_score <<- score
        best_position <<- position
      }
    }
  )
)

Swarm <- setRefClass("Swarm",
  fields = list(particles = "list", global_best_position = "numeric", global_best_score = "numeric"),
  methods = list(
    initialize = function(num_particles, dimensions, bounds) {
      particles <<- lapply(1:num_particles, function(i) Particle$new(dimensions, bounds))
      global_best_position <<- particles[[1]]$best_position
      global_best_score <<- particles[[1]]$best_score
    },
    update_global_best = function() {
      for (particle in particles) {
        if (particle$best_score < global_best_score) {
          global_best_score <<- particle$best_score
          global_best_position <<- particle$best_position
        }
      }
    },
    iterate = function(objective_function) {
      for (particle in particles) {
        particle$update_velocity(global_best_position)
        particle$update_position(objective_function$bounds)
        particle$evaluate(objective_function)
      }
      update_global_best()
    }
  )
)

ObjectiveFunction <- setRefClass("ObjectiveFunction",
  fields = list(bounds = "numeric"),
  methods = list(
    initialize = function(bounds) {
      bounds <<- bounds
    },
    call = function(position) {
      x <<- position[1]
      y <<- position[2]
      return((x ^ 2 + y - 11) ^ 2 + (x + y ^ 2 - 7) ^ 2)
    }
  )
)

main <- function() {
  dimensions <<- 2
  num_particles <<- 30
  bounds <<- c(-5, 5)
  objective_function <<- ObjectiveFunction$new(bounds)
  swarm <<- Swarm$new(num_particles, dimensions, bounds)
  for (i in 1:100) {
    swarm$iterate(objective_function)
    if (swarm$global_best_score < 1e-06) {
      break
    }
  }
  print(paste("Best position:", swarm$global_best_position))
  print(paste("Best score:", swarm$global_best_score))
}

main()