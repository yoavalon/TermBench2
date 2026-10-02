FluidCell <- function(state) {
  list(state = state, update_state = function(neighbors) {
    self <- environment()
    self$state <- sum(sapply(neighbors, function(n) n$state)) %/% 3
  })
}

Grid <- function(size) {
  list(size = size, 
       cells = array(list(), dim = c(size, size)),
       get_neighbors = function(x, y) {
         neighbors <- list()
         for (dx in c(-1, 0, 1)) {
           for (dy in c(-1, 0, 1)) {
             if (dx == 0 && dy == 0) next
             nx <- x + dx
             ny <- y + dy
             if (nx >= 1 && nx <= self$size && ny >= 1 && ny <= self$size) {
               neighbors[[length(neighbors) + 1]] <- self$cells[nx, ny]
             }
           }
         }
         neighbors
       },
       update_grid = function() {
         new_cells <- array(list(), dim = c(self$size, self$size))
         for (x in 1:self$size) {
           for (y in 1:self$size) {
             neighbors <- self$get_neighbors(x, y)
             new_cells[x, y] <- FluidCell(0)
             new_cells[[x, y]]$update_state(neighbors)
           }
         }
         self$cells <- new_cells
       })
}

main <- function() {
  grid_size <- 10
  grid <- Grid(grid_size)
  while (TRUE) {
    grid$update_grid()
  }
}

main()