r
library(pracma)

Particle <- setRefClass("Particle",
                      fields = list(position = "numeric",
                                   velocity = "numeric",
                                   best_position = "numeric",
                                   best_score = "numeric"),
                      methods = list(
                        initialize = function(dimensions, bounds) {
                          position <<- runif(dimensions, bounds[1], bounds[2])
                          velocity <<- rep(0.0, dimensions)
                          best_position <<- copy(position)
                          best_score <<- Inf
                        }
                      ))

Swarm <- setRefClass("Swarm",
                    fields = list(particles = "list",
                                 bounds = "numeric",
                                 function = "function",
                                 w = "numeric",
                                 c1 = "numeric",
                                 c2 = "numeric",
                                 best_swarm_position = "numeric",
                                 best_swarm_score = "numeric"),
                    methods = list(
                      initialize = function(particles, bounds, function, w, c1, c2) {
                        particles <<- particles
                        bounds <<- bounds
                        function <<- function
                        w <<- w
                        c1 <<- c1
                        c2 <<- c2
                        best_swarm_position <<- rep(0.0, length(bounds))
                        best_swarm_score <<- Inf
                      },
                      evaluate = function() {
                        for (particle in particles) {
                          score <<- function(particle$position)
                          if (score < particle$best_score) {
                            particle$best_score <<- score
                            particle$best_position <<- copy(particle$position)
                          }
                          if (score < best_swarm_score) {
                            best_swarm_score <<- score
                            best_swarm_position <<- copy(particle$position)
                          }
                        }
                      },
                      update = function() {
                        for (particle in particles) {
                          for (i in seq_along(particle$position)) {
                            r1 <<- runif(1)
                            r2 <<- runif(1)
                            velocity_cognitive <<- c1 * r1 * (particle$best_position[i] - particle$position[i])
                            velocity_social <<- c2 * r2 * (best_swarm_position[i] - particle$position[i])
                            particle$velocity[i] <<- w * particle$velocity[i] + velocity_cognitive + velocity_social
                            particle$position[i] <<- particle$position[i] + particle$velocity[i]
                            particle$position[i] <<- max(bounds[1], min(bounds[2], particle$position[i]))
                          }
                        }
                      }
                    ))

objective_function <- function(x) {
  sum(x^2)
}

optimize <- function(dimensions, bounds, num_particles, max_iterations, w, c1, c2) {
  particles <<- lapply(1:num_particles, function(_) Particle$new(dimensions, bounds))
  swarm <<- Swarm$new(particles, bounds, objective_function, w, c1, c2)
  for (i in 1:max_iterations) {
    swarm$evaluate()
    swarm$update()
  }
  return(list(swarm$best_swarm_position, swarm$best_swarm_score))
}

dimensions <<- 2
bounds <<- c(-10, 10)
num_particles <<- 30
max_iterations <<- 100
w <<- 0.729
c1 <<- 1.494
c2 <<- 1.494
result <<- optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2)
cat('Best position:', result[[1]], '\n')
cat('Best score:', result[[2]], '\n')