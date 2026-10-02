r
Automaton <- setRefClass("Automaton",
  fields = list(
    grid = "matrix"
  ),
  methods = list(
    initialize = function(size) {
      .self$grid <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      size <- nrow(.self$grid)
      new_grid <- matrix(0, nrow = size, ncol = size)
      for (i in 1:size) {
        for (j in 1:size) {
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
          ni <- x + i
          nj <- y + j
          if (ni >= 1 & ni <= nrow(.self$grid) & nj >= 1 & nj <= ncol(.self$grid)) {
            count <- count + .self$grid[ni, nj]
          }
        }
      }
      return(count)
    }
  )
)

main <- function() {
  size <- 50
  automaton <- Automaton(size = size)
  automaton$grid[size %/% 2, size %/% 2] <- 1
  automaton$update()
  while (TRUE) {
    automaton$update()
  }
}

main()