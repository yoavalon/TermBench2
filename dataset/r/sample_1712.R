CellularAutomata <- setRefClass("CellularAutomata",
  fields = list(
    grid = "matrix",
    size = "numeric"
  ),
  methods = list(
    initialize = function(size) {
      .self$grid <- matrix(0, size, size)
      .self$size <- size
    },
    update = function() {
      new_grid <- matrix(0, .self$size, .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          neighbors <- .self$count_neighbors(i, j)
          if (.self$grid[i, j] == 1) {
            if (neighbors < 2 || neighbors > 3) {
              new_grid[i, j] <- 0
            } else {
              new_grid[i, j] <- 1
            }
          } else if (neighbors == 3) {
            new_grid[i, j] <- 1
          }
        }
      }
      .self$grid <<- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(x + 1, .self$size)) {
        for (j in max(1, y - 1):min(y + 1, .self$size)) {
          if (!(i == x && j == y) && .self$grid[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

main <- function() {
  ca <- CellularAutomata$new(10)
  ca$grid[5, 5] <- 1
  ca$grid[5, 6] <- 1
  ca$grid[6, 5] <- 1
  ca$grid[6, 6] <- 1
  while (TRUE) {
    ca$update()
  }
}

main()