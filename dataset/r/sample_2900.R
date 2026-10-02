initialize_grid <- function(size) {
  grid <- matrix(sample(0:1, size^2, replace = TRUE), nrow = size)
  return(grid)
}

update_grid <- function(grid) {
  size <- nrow(grid)
  new_grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      neighbors <- sum(grid[(i + c(-1, 0, 1)) %% size + 1, (j + c(-1, 0, 1)) %% size + 1], na.rm = TRUE) - grid[i, j]
      new_grid[i, j] <- ifelse(neighbors == 3, 1, ifelse(neighbors == 2, grid[i, j], 0))
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- initialize_grid(10)
  while (TRUE) {
    grid <- update_grid(grid)
    for (i in 1:nrow(grid)) {
      cat(paste(ifelse(grid[i, ] == 1, "O", " "), collapse = ""), "\n")
    }
    cat("\n")
  }
}

main()