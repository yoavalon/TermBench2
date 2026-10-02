r
library(MASS)

AutomatonCell <- function(state) {
  list(state = state)
}

update_state <- function(cell, neighbors) {
  alive_neighbors <- sum(sapply(neighbors, function(n) n$state))
  if (cell$state == 1) {
    if (alive_neighbors < 2 || alive_neighbors > 3) {
      cell$state <- 0
    }
  } else if (alive_neighbors == 3) {
    cell$state <- 1
  }
  cell
}

AutomatonGrid <- function(size) {
  grid <- array(apply(matrix(0, size, size), c(1, 2), function(x, y) AutomatonCell(sample(0:1, 1))), dim = c(size, size))
  list(grid = grid)
}

get_neighbors <- function(grid, x, y) {
  size <- dim(grid)[1]
  neighbors <- list()
  for (i in -1:1) {
    for (j in -1:1) {
      if (i == 0 && j == 0) {
        next
      }
      nx <- x + i
      ny <- y + j
      if (nx >= 1 && nx <= size && ny >= 1 && ny <= size) {
        neighbors <- c(neighbors, grid[nx, ny])
      }
    }
  }
  neighbors
}

update_grid <- function(grid) {
  size <- dim(grid)[1]
  new_grid <- array(apply(matrix(0, size, size), c(1, 2), function(x, y) AutomatonCell(0)), dim = c(size, size))
  for (x in 1:size) {
    for (y in 1:size) {
      neighbors <- get_neighbors(grid, x, y)
      new_grid[x, y] <- update_state(grid[x, y], neighbors)
    }
  }
  grid$grid <- new_grid
}

simulate <- function() {
  size <- 50
  grid <- AutomatonGrid(size)
  while (TRUE) {
    update_grid(grid)
  }
}

simulate()