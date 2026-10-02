FluidGrid <- setRefClass("FluidGrid",
  fields = list(
    grid = "matrix",
    size = "numeric"
  ),
  methods = list(
    initialize = function(size) {
      .self$grid <- matrix(0, nrow = size, ncol = size)
      .self$size <- size
    },
    update = function() {
      new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          new_grid[i, j] <- .self$calculate_next_state(i, j)
        }
      }
      .self$grid <<- new_grid
    },
    calculate_next_state = function(x, y) {
      neighbors <- .self$get_neighbors(x, y)
      count <- sum(neighbors)
      if (.self$grid[x, y] == 0) {
        return(ifelse(count > 2, 1, 0))
      } else {
        return(ifelse(count %in% c(2, 3), 1, 0))
      }
    },
    get_neighbors = function(x, y) {
      directions <- cbind(c(-1, -1, -1, 0, 0, 1, 1, 1), c(-1, 0, 1, -1, 1, -1, 0, 1))
      neighbors <- c()
      for (k in 1:nrow(directions)) {
        dx <- directions[k, 1]
        dy <- directions[k, 2]
        nx <- x + dx
        ny <- y + dy
        if (nx >= 1 && nx <= .self$size && ny >= 1 && ny <= .self$size) {
          neighbors <- c(neighbors, .self$grid[nx, ny])
        } else {
          neighbors <- c(neighbors, 0)
        }
      }
      return(neighbors)
    }
  )
)

main <- function() {
  size <- 10
  grid <- new("FluidGrid", size = size)
  while (TRUE) {
    grid$update()
  }
}

main()