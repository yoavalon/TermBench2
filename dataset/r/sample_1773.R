FluidCell <- function(state) {
  list(state = state, update_state = function(neighbors) {
    active_neighbors <- sum(sapply(neighbors, function(neighbor) neighbor$state > 0))
    if (active_neighbors > 4) {
      this$state <- 2
    } else if (active_neighbors < 2) {
      this$state <- 0
    } else {
      this$state <- 1
    }
  })
}

FluidGrid <- function(size) {
  grid <- array(dim = c(size, size), list())
  for (i in 1:size) {
    for (j in 1:size) {
      grid[i, j] <- FluidCell(0)
    }
  }
  list(grid = grid, size = size, get_neighbors = function(x, y) {
    neighbors <- list()
    for (i in x - 1:x + 1) {
      for (j in y - 1:y + 1) {
        if (i >= 1 && i <= size && j >= 1 && j <= size && !(i == x && j == y)) {
          neighbors <- c(neighbors, grid[i, j])
        }
      }
    }
    neighbors
  }, update_grid = function() {
    new_grid <- array(dim = c(size, size), list())
    for (i in 1:size) {
      for (j in 1:size) {
        neighbors <- this$get_neighbors(i, j)
        new_grid[i, j] <- FluidCell(0)
        new_grid[i, j]$update_state(neighbors)
      }
    }
    this$grid <- new_grid
  })
}

main <- function() {
  size <- 10
  grid <- FluidGrid(size)
  while (TRUE) {
    grid$update_grid()
  }
}

main()