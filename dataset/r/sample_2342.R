FluidCell <- function(state) {
  list(state = state, update = function(neighbors) {
    avg_state <- mean(sapply(neighbors, function(n) n$state))
    self$state <- avg_state
  })
}

Grid <- function(size, initial_state) {
  cells <- array(apply(array(TRUE, dim = c(size, size)), c(1, 2), function(x, y) FluidCell(initial_state)), dim = c(size, size))
  list(size = size, cells = cells, get_neighbors = function(x, y) {
    neighbors <- list()
    for (dx in c(-1, 0, 1)) {
      for (dy in c(-1, 0, 1)) {
        if (dx == 0 && dy == 0) {
          next
        }
        nx <- x + dx
        ny <- y + dy
        if (nx >= 1 && nx <= self$size && ny >= 1 && ny <= self$size) {
          neighbors <- c(neighbors, self$cells[nx, ny])
        }
      }
    }
    neighbors
  }, update = function() {
    new_cells <- array(apply(array(TRUE, dim = c(self$size, self$size)), c(1, 2), function(x, y) FluidCell(self$cells[x, y]$state)), dim = c(self$size, self$size))
    for (x in 1:self$size) {
      for (y in 1:self$size) {
        neighbors <- self$get_neighbors(x, y)
        new_cells[x, y]$update(neighbors)
      }
    }
    self$cells <- new_cells
  })
}

main <- function() {
  grid_size <- 10
  initial_state <- 0.5
  grid <- Grid(grid_size, initial_state)
  while (TRUE) {
    grid$update()
  }
}

main()