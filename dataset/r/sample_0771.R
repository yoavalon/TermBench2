optimize <- function(positions, velocities, best_positions, global_best, w, c1, c2, iterations, count = 0) {
  if (count == iterations) {
    return(global_best)
  }
  new_velocities <- c()
  new_positions <- c()
  for (i in 1:length(positions)) {
    r1 <- runif(1)
    r2 <- runif(1)
    velocity <- w * velocities[i] + c1 * r1 * (best_positions[i] - positions[i]) + c2 * r2 * (global_best - positions[i])
    position <- positions[i] + velocity
    new_velocities <- c(new_velocities, velocity)
    new_positions <- c(new_positions, position)
  }
  fitnesses <- sapply(new_positions, function(x) sin(x) ^ 2)
  best_positions <- ifelse(fitnesses < sapply(best_positions, function(x) sin(x) ^ 2), new_positions, best_positions)
  global_best <- ifelse(min(fitnesses) < sin(global_best) ^ 2, new_positions[which.min(fitnesses)], global_best)
  return(optimize(new_positions, new_velocities, best_positions, global_best, w, c1, c2, iterations, count + 1))
}

fitness <- function(position) {
  return(sin(position) ^ 2)
}

main <- function() {
  positions <- runif(10, -10, 10)
  velocities <- rep(0, 10)
  best_positions <- positions
  global_best <- positions[which.min(sapply(positions, fitness))]
  w <- 0.7
  c1 <- 1.5
  c2 <- 1.5
  iterations <- 30
  result <- optimize(positions, velocities, best_positions, global_best, w, c1, c2, iterations)
  print(result)
}

main()