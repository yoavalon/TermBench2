library(abind)

update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- grid
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- grid[i, (j - 1) %% cols + 1] + grid[i, (j + 1) %% cols + 1] + 
                   grid[(i - 1) %% rows + 1, j] + grid[(i + 1) %% rows + 1, j] + 
                   grid[(i - 1) %% rows + 1, (j - 1) %% cols + 1] + grid[(i - 1) %% rows + 1, (j + 1) %% cols + 1] + 
                   grid[(i + 1) %% rows + 1, (j - 1) %% cols + 1] + grid[(i + 1) %% rows + 1, (j + 1) %% cols + 1]
      if (grid[i, j] == 1) {
        if (neighbors < 2 | neighbors > 3) {
          new_grid[i, j] <- 0
        }
      } else if (neighbors == 3) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid_size <- 10
  grid <- matrix(sample(0:1, grid_size^2, replace = TRUE), nrow = grid_size)
  while (TRUE) {
    grid <- update_grid(grid)
    print(grid)
    cat(rep("-", 20), "\n")
  }
}

main()