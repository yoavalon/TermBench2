FluidCell <- function(state = 0) {
  list(state = state)
}

update_state <- function(cell, neighbors) {
  count <- sum(sapply(neighbors, function(n) n$state == 1))
  if (count == 3) {
    cell$state <- 1
  } else if (count < 2 | count > 3) {
    cell$state <- 0
  }
  return(cell)
}

Grid <- function(size, initial_state = NULL) {
  if (is.null(initial_state)) {
    initial_state <- matrix(0, nrow = size, ncol = size)
  }
  grid <- lapply(1:size, function(i) lapply(1:size, function(j) FluidCell(initial_state[i, j])))
  list(size = size, grid = grid)
}

get_neighbors <- function(grid, x, y) {
  directions <- cbind(c(-1, -1, -1, 0, 0, 1, 1, 1), c(-1, 0, 1, -1, 1, -1, 0, 1))
  neighbors <- list()
  for (k in 1:nrow(directions)) {
    dx <- directions[k, 1]
    dy <- directions[k, 2]
    nx <- x + dx
    ny <- y + dy
    if (nx >= 1 & nx <= grid$size & ny >= 1 & ny <= grid$size) {
      neighbors[[length(neighbors) + 1]] <- grid$grid[[nx]][[ny]]
    }
  }
  return(neighbors)
}

update_grid <- function(grid) {
  new_grid <- matrix(0, nrow = grid$size, ncol = grid$size)
  for (i in 1:grid$size) {
    for (j in 1:grid$size) {
      neighbors <- get_neighbors(grid, i, j)
      grid$grid[[i]][[j]] <- update_state(grid$grid[[i]][[j]], neighbors)
      new_grid[i, j] <- grid$grid[[i]][[j]]$state
    }
  }
  grid$grid <- lapply(1:grid$size, function(i) lapply(1:grid$size, function(j) FluidCell(new_grid[i, j])))
}

main <- function() {
  size <- 10
  initial_state <- matrix(c(0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                            0, 0, 1, 1, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0, 0, 0), nrow = size, byrow = TRUE)
  grid <- Grid(size, initial_state)
  while (TRUE) {
    update_grid(grid)
  }
}

main()