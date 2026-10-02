FluidSimulator <- function(grid_size, rules) {
  grid <- matrix(0, nrow = grid_size, ncol = grid_size)
  
  update <- function() {
    new_grid <- matrix(0, nrow = nrow(grid), ncol = ncol(grid))
    for (i in 1:nrow(grid)) {
      for (j in 1:ncol(grid)) {
        new_grid[i, j] <- rules$apply(grid, i, j)
      }
    }
    grid <<- new_grid
  }
  
  display <- function() {
    for (row in grid) {
      cat(paste(row, collapse = " "), "\n")
    }
    cat("\n")
  }
  
  list(grid = grid, update = update, display = display)
}

RuleSet <- function() {
  apply <- function(grid, x, y) {
    neighbors <- count_neighbors(grid, x, y)
    if (neighbors == 2) {
      return(1)
    } else {
      return(0)
    }
  }
  
  count_neighbors <- function(grid, x, y) {
    count <- 0
    for (i in max(1, x - 1):min(nrow(grid), x + 1)) {
      for (j in max(1, y - 1):min(ncol(grid), y + 1)) {
        if (!(i == x && j == y) && grid[i, j] == 1) {
          count <- count + 1
        }
      }
    }
    return(count)
  }
  
  list(apply = apply, count_neighbors = count_neighbors)
}

main <- function() {
  grid_size <- 10
  rules <- RuleSet()
  simulator <- FluidSimulator(grid_size, rules)
  simulator$grid[4, 4] <- 1
  simulator$grid[5, 4] <- 1
  simulator$grid[4, 5] <- 1
  while (TRUE) {
    simulator$display()
    simulator$update()
  }
}

main()