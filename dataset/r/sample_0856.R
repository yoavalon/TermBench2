library(runif)

Particle <- setRefClass("Particle",
                        fields = list(
                          position = "list",
                          velocity = "list",
                          best_position = "list",
                          best_score = "numeric"
                        ),
                        methods = list(
                          initialize = function(dimensions, bounds) {
                            position <<- lapply(bounds, function(b) runif(1, min = b[1], max = b[2]))
                            velocity <<- lapply(rep(1, dimensions), function(x) runif(1, min = -1, max = 1))
                            best_position <<- position
                            best_score <<- Inf
                          },
                          
                          update_velocity = function(global_best, w, c1, c2) {
                            for (i in 1:length(velocity)) {
                              r1 <- runif(1)
                              r2 <- runif(1)
                              cognitive <- c1 * r1 * (best_position[[i]] - position[[i]])
                              social <- c2 * r2 * (global_best[i] - position[[i]])
                              velocity[[i]] <<- w * velocity[[i]] + cognitive + social
                            }
                          },
                          
                          update_position = function(bounds) {
                            for (i in 1:length(position)) {
                              position[[i]] <<- position[[i]] + velocity[[i]]
                              position[[i]] <<- max(bounds[[i]][1], min(bounds[[i]][2], position[[i]]))
                            }
                          }
                        ))

Swarm <- setRefClass("Swarm",
                     fields = list(
                       particles = "list",
                       best_position = "list",
                       best_score = "numeric",
                       function = "function"
                     ),
                     methods = list(
                       initialize = function(num_particles, dimensions, bounds, function) {
                         particles <<- replicate(num_particles, Particle$new(dimensions, bounds), simplify = FALSE)
                         best_position <<- NULL
                         best_score <<- Inf
                         function <<- function
                       },
                       
                       optimize = function(max_iterations, w, c1, c2) {
                         for (i in 1:max_iterations) {
                           for (j in 1:length(particles)) {
                             particle <- particles[[j]]
                             score <<- function(particle$position)
                             if (score < particle$best_score) {
                               particle$best_score <<- score
                               particle$best_position <<- particle$position
                             }
                             if (score < best_score) {
                               best_score <<- score
                               best_position <<- particle$position
                             }
                           }
                           for (j in 1:length(particles)) {
                             particles[[j]]$update_velocity(best_position, w, c1, c2)
                             particles[[j]]$update_position(bounds)
                           }
                         }
                       }
                     ))

objective_function <- function(x) {
  sum((x - 2)^2)
}

main <- function() {
  dimensions <- 3
  bounds <- replicate(dimensions, c(-10, 10), simplify = FALSE)
  num_particles <- 20
  max_iterations <- 100
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  swarm <- Swarm$new(num_particles, dimensions, bounds, objective_function)
  swarm$optimize(max_iterations, w, c1, c2)
  print(list(swarm$best_position, swarm$best_score))
}

main()