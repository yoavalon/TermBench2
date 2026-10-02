Automaton <- setRefClass("Automaton",
  fields = list(grid = "matrix", size = "numeric"),
  methods = list(
    initialize = function(size) {
      .self$size <- size
      .self$grid <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          neighbors <- .self$count_neighbors(i, j)
          if (.self$grid[i, j] == 0 & neighbors == 3) {
            new_grid[i, j] <- 1
          } else if (.self$grid[i, j] == 1 & (neighbors < 2 | neighbors > 3)) {
            new_grid[i, j] <- 0
          } else {
            new_grid[i, j] <- .self$grid[i, j]
          }
        }
      }
      .self$grid <<- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in -1:1) {
        for (j in -1:1) {
          if (i == 0 & j == 0) {
            next
          }
          nx <- x + i
          ny <- y + j
          if (nx >= 1 & nx <= .self$size & ny >= 1 & ny <= .self$size) {
            count <- count + .self$grid[nx, ny]
          }
        }
      }
      return(count)
    }
  )
)

run_simulation <- function(size) {
  automaton <- Automaton(size = size)
  automaton$grid[1, 1] <- 1
  automaton$grid[1, 2] <- 1
  automaton$grid[2, 1] <- 1
  automaton$grid[2, 2] <- 1
  while (TRUE) {
    automaton$update()
  }
}

main <- function() {
  run_simulation(5)
}

main()