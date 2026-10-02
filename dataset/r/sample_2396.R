r
FluidCell <- function(value) {
  value <- value
  update <- function(neighbors) {
    value <<- mean(sapply(neighbors, function(n) n$value))
  }
  return(list(value = value, update = update))
}

FluidGrid <- function(size) {
  grid <- array(NA, dim = c(size, size))
  for (i in 1:size) {
    for (j in 1:size) {
      grid[i, j] <- FluidCell(0.0)
    }
  }
  get_neighbors <- function(x, y) {
    directions <- list(c(-1, 0), c(1, 0), c(0, -1), c(0, 1))
    neighbors <- list()
    for (d in directions) {
      nx <- x + d[1]
      ny <- y + d[2]
      if (nx >= 1 && nx <= size && ny >= 1 && ny <= size) {
        neighbors[[length(neighbors) + 1]] <- grid[nx, ny]
      }
    }
    return(neighbors)
  }
  update_cells <- function() {
    new_grid <- array(NA, dim = c(size, size))
    for (i in 1:size) {
      for (j in 1:size) {
        neighbors <- get_neighbors(i, j)
        new_grid[i, j] <- FluidCell(0.0)
        new_grid[i, j]$update(neighbors)
      }
    }
    grid <<- new_grid
  }
  return(list(grid = grid, get_neighbors = get_neighbors, update_cells = update_cells))
}

main <- function() {
  size <- 100
  fluid_grid <- FluidGrid(size)
  for (cell in fluid_grid$grid[1, ]) {
    cell$value <- 1.0
  }
  while (TRUE) {
    fluid_grid$update_cells()
  }
}

main()