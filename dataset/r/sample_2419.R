cellular_automata <- function(grid, steps) {
  for (step in 1:steps) {
    new_grid <- replicate(length(grid), rep(0, length(grid[[1]])), simplify = FALSE)
    for (i in 1:length(grid)) {
      for (j in 1:length(grid[[1]])) {
        neighbors <- sum(c(
          ifelse(i > 1, grid[[i - 1]][[j]], 0),
          ifelse(i < length(grid), grid[[i + 1]][[j]], 0),
          ifelse(j > 1, grid[[i]][[j - 1]], 0),
          ifelse(j < length(grid[[1]]), grid[[i]][[j + 1]], 0)
        ))
        new_grid[[i]][[j]] <- ifelse(neighbors == 2 || (neighbors == 3 && grid[[i]][[j]] == 1), 1, 0)
      }
    }
    grid <- new_grid
  }
  return(grid)
}

initial_grid <- list(c(0, 1, 0), c(0, 1, 0), c(0, 1, 0))
steps <- 5
result <- cellular_automata(initial_grid, steps)
print(result)