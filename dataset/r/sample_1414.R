library(stats)

set.seed(123)

Swarm <- function(size, dimensions) {
  positions <- replicate(size, runif(dimensions))
  velocities <- replicate(size, runif(dimensions))
  best_positions <- positions
  best_score <- Inf
  
  update_personal_best <- function(score) {
    if (score < best_score) {
      best_score <<- score
      best_positions <<- positions
    }
  }
  
  update_velocity <- function(global_best) {
    inertia <- 0.5
    cognitive <- 1.5
    social <- 1.5
    for (i in 1:size) {
      for (j in 1:dimensions) {
        r1 <- runif(1)
        r2 <- runif(1)
        velocities[i, j] <<- inertia * velocities[i, j] + cognitive * r1 * (best_positions[i, j] - positions[i, j]) + social * r2 * (global_best[j] - positions[i, j])
      }
    }
  }
  
  update_position <- function() {
    for (i in 1:size) {
      for (j in 1:dimensions) {
        positions[i, j] <<- positions[i, j] + velocities[i, j]
      }
    }
  }
  
  list(positions = positions, velocities = velocities, best_positions = best_positions, best_score = best_score,
       update_personal_best = update_personal_best, update_velocity = update_velocity, update_position = update_position)
}

Environment <- function(swarm) {
  evaluate <- function() {
    scores <- sapply(1:nrow(swarm$positions), function(i) sum(swarm$positions[i, ]^2))
    return(scores)
  }
  
  find_global_best <- function(scores) {
    global_best_index <- which.min(scores)
    return(swarm$positions[global_best_index, ])
  }
  
  list(swarm = swarm, evaluate = evaluate, find_global_best = find_global_best)
}

main <- function() {
  swarm <- Swarm(size = 10, dimensions = 3)
  environment <- Environment(swarm)
  iterations <- 50
  for (i in 1:iterations) {
    scores <- environment$evaluate()
    global_best <- environment$find_global_best(scores)
    swarm$update_personal_best(min(scores))
    swarm$update_velocity(global_best)
    swarm$update_position()
  }
  cat('Best score:', swarm$best_score, '\n')
}

main()