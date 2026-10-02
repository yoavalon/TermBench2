optimize <- function(positions, velocities, personal_best, global_best, iteration, max_iterations) {
  if (iteration >= max_iterations) {
    return(global_best)
  }
  new_positions <- c()
  new_velocities <- c()
  for (i in 1:length(positions)) {
    r1 <- runif(1)
    r2 <- runif(1)
    new_velocity <- velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i])
    new_position <- positions[i] + new_velocity
    new_positions <- c(new_positions, new_position)
    new_velocities <- c(new_velocities, new_velocity)
  }
  new_global_best <- min(new_positions, key = fitness)
  return(optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations))
}

fitness <- function(x) {
  return(x^2)
}

main <- function() {
  positions <- runif(10, min = -10, max = 10)
  velocities <- rep(0.0, 10)
  personal_best <- positions
  global_best <- min(positions, key = fitness)
  optimize(positions, velocities, personal_best, global_best, 0, 100)
}

main()