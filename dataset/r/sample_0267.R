Grid <- R6::R6Class("Grid",
  public = list(
    size = NULL,
    grid = NULL,
    boundary = NULL,
    initialize = function(size, boundary) {
      self$size <- size
      self$grid <- matrix(0, nrow = size, ncol = size)
      self$boundary <- boundary
    },
    update = function() {
      new_grid <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$boundary_condition(i, j)
          new_grid[i, j] <- self$apply_rules(neighbors, self$grid[i, j])
        }
      }
      self$grid <- new_grid
    },
    boundary_condition = function(x, y) {
      neighbors <- c()
      for (dx in c(-1, 0, 1)) {
        for (dy in c(-1, 0, 1)) {
          if (dx == 0 && dy == 0) {
            next
          }
          nx <- (x + dx)
          ny <- (y + dy)
          if (self$boundary == 'fixed') {
            if (nx >= 1 && nx <= self$size && ny >= 1 && ny <= self$size) {
              neighbors <- c(neighbors, self$grid[nx, ny])
            }
          } else if (self$boundary == 'periodic') {
            neighbors <- c(neighbors, self$grid[(nx + self$size - 1) %% self$size + 1, (ny + self$size - 1) %% self$size + 1])
          }
        }
      }
      return(neighbors)
    },
    apply_rules = function(neighbors, current) {
      count <- sum(neighbors)
      if (current == 1) {
        if (count < 2 || count > 3) {
          return(0)
        }
        return(1)
      } else {
        if (count == 3) {
          return(1)
        }
        return(0)
      }
    }
  )
)

main <- function() {
  size <- 10
  boundary <- 'periodic'
  grid <- Grid$new(size, boundary)
  steps <- 50
  for (i in 1:steps) {
    grid$update()
  }
}

main()