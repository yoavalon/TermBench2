FluidCell <- function(state) {
  list(state = state)
}

update_FluidCell <- function(cell, neighbors) {
  new_state <- sum(sapply(neighbors, function(n) n$state)) %/% length(neighbors)
  cell$state <- new_state
  return(cell)
}

Grid <- function(size) {
  cells <- array(list(), dim = c(size, size))
  for (i in 1:size) {
    for (j in 1:size) {
      cells[i, j] <- FluidCell(0)
    }
  }
  list(size = size, cells = cells)
}

get_neighbors_Grid <- function(grid, x, y) {
  directions <- cbind(c(-1, 1, 0, 0), c(0, 0, -1, 1))
  neighbors <- list()
  for (d in 1:nrow(directions)) {
    nx <- x + directions[d, 1]
    ny <- y + directions[d, 2]
    if (nx >= 1 && nx <= grid$size && ny >= 1 && ny <= grid$size) {
      neighbors <- c(neighbors, grid$cells[nx, ny])
    }
  }
  return(neighbors)
}

update_Grid <- function(grid) {
  new_grid <- array(list(), dim = c(grid$size, grid$size))
  for (i in 1:grid$size) {
    for (j in 1:grid$size) {
      neighbors <- get_neighbors_Grid(grid, i, j)
      new_grid[i, j] <- update_FluidCell(grid$cells[i, j], neighbors)
    }
  }
  grid$cells <- new_grid
  return(grid)
}

Simulation <- function(grid_size, steps) {
  list(grid = Grid(grid_size), steps = steps)
}

run_Simulation <- function(simulation) {
  for (i in 1:simulation$steps) {
    simulation$grid <- update_Grid(simulation$grid)
  }
}

main <- function() {
  simulation <- Simulation(10, 50)
  run_Simulation(simulation)
}

main()