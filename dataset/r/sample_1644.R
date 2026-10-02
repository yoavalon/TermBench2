update_position <- function(position, velocity, best_position, global_best) {
  for (i in 1:length(position)) {
    r1 <- runif(1)
    r2 <- runif(1)
    cognitive <- r1 * (best_position[i] - position[i])
    social <- r2 * (global_best[i] - position[i])
    velocity[i] <<- 0.7 * velocity[i] + cognitive + social
    position[i] <<- position[i] + velocity[i]
  }
}

optimize <- function() {
  dimensions <- 30
  swarm_size <- 50
  positions <- replicate(swarm_size, runif(dimensions))
  velocities <- replicate(swarm_size, runif(dimensions))
  best_positions <- positions
  global_best <- positions[which.min(apply(positions, 1, sum)), ]
  while (TRUE) {
    for (i in 1:swarm_size) {
      update_position(positions[i, ], velocities[i, ], best_positions[i, ], global_best)
      fitness <- sum(positions[i, ])
      if (fitness < sum(best_positions[i, ])) {
        best_positions[i, ] <<- positions[i, ]
        if (fitness < sum(global_best)) {
          global_best <<- positions[i, ]
        }
      }
    }
  }
}

main <- function() {
  optimize()
}

main()