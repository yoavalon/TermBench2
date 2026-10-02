Swarm <- function(size, dimensions) {
  this <- list()
  
  this$size <- size
  this$dimensions <- dimensions
  this$positions <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
  this$velocities <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
  this$best_positions <- replicate(size, rep(0.0, dimensions), simplify = FALSE)
  this$best_scores <- rep(Inf, size)
  
  this$update_best_positions <- function(scores) {
    for (i in 1:size) {
      if (scores[i] < this$best_scores[i]) {
        this$best_scores[i] <- scores[i]
        this$best_positions[[i]] <- this$positions[[i]]
      }
    }
  }
  
  this$update_velocities <- function(global_best_position, w = 0.7, c1 = 1.5, c2 = 1.5) {
    for (i in 1:size) {
      for (j in 1:dimensions) {
        r1 <- 0.5
        r2 <- 0.5
        this$velocities[[i]][j] <- w * this$velocities[[i]][j] + c1 * r1 * (this$best_positions[[i]][j] - this$positions[[i]][j]) + c2 * r2 * (global_best_position[j] - this$positions[[i]][j])
      }
    }
  }
  
  this$update_positions <- function() {
    for (i in 1:size) {
      for (j in 1:dimensions) {
        this$positions[[i]][j] <- this$positions[[i]][j] + this$velocities[[i]][j]
      }
    }
  }
  
  return(this)
}

fitness_function <- function(position) {
  return(sum(position^2))
}

main <- function() {
  swarm_size <- 30
  dimensions <- 2
  max_iterations <- 100
  swarm <- Swarm(swarm_size, dimensions)
  
  for (iteration in 1:max_iterations) {
    scores <- sapply(swarm$positions, fitness_function)
    global_best_index <- which.min(scores)
    global_best_position <- swarm$positions[[global_best_index]]
    swarm$update_best_positions(scores)
    swarm$update_velocities(global_best_position)
    swarm$update_positions()
  }
  
  best_score <- min(scores)
  best_position <- swarm$positions[[which.min(scores)]]
  cat('Best score:', best_score, '\n')
  cat('Best position:', best_position, '\n')
}

main()