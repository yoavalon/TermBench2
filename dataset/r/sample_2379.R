library(methods)

setClass("FluidCell",
         slots = c(
           x = "numeric",
           y = "numeric",
           pressure = "numeric",
           velocity = "numeric"
         ))

setMethod("initialize", "FluidCell",
          function(.Object, x, y) {
            .Object@x <- x
            .Object@y <- y
            .Object@pressure <- 0.0
            .Object@velocity <- c(0.0, 0.0)
            return(.Object)
          })

update_pressure <- function(cell, neighbors) {
  total_pressure <- sum(sapply(neighbors, function(n) n@pressure))
  cell@pressure <- total_pressure / length(neighbors)
}

update_velocity <- function(cell, neighbors) {
  dx <- sum(sapply(neighbors, function(n) n@velocity[1]))
  dy <- sum(sapply(neighbors, function(n) n@velocity[2]))
  cell@velocity <- c(dx / length(neighbors), dy / length(neighbors))
}

get_neighbors <- function(grid, x, y) {
  neighbors <- list()
  directions <- list(c(-1, 0), c(1, 0), c(0, -1), c(0, 1))
  for (dir in directions) {
    nx <- x + dir[1]
    ny <- y + dir[2]
    if (nx >= 0 && nx < nrow(grid) && ny >= 0 && ny < ncol(grid)) {
      neighbors <- c(neighbors, grid[nx + 1, ny + 1])
    }
  }
  return(neighbors)
}

simulate <- function(grid) {
  while (TRUE) {
    for (cell in grid) {
      neighbors <- get_neighbors(grid, cell@x, cell@y)
      update_pressure(cell, neighbors)
      update_velocity(cell, neighbors)
    }
  }
}

main <- function() {
  width <- 10
  height <- 10
  grid <- array(data = NULL, dim = c(width, height))
  for (x in 1:width) {
    for (y in 1:height) {
      grid[x, y] <- new("FluidCell", x = x - 1, y = y - 1)
    }
  }
  simulate(grid)
}

main()