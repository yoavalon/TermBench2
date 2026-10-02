library(Matrix)

AutomataGrid <- setRefClass("AutomataGrid",
  fields = list(grid = "matrix"),
  methods = list(
    initialize = function(size) {
      .self$grid <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_grid <- matrix(0, nrow = nrow(.self$grid), ncol = ncol(.self$grid))
      for (i in 1:nrow(.self$grid)) {
        for (j in 1:ncol(.self$grid)) {
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
      .self$grid <- new_grid
    },
    count_neighbors = function(x, y) {
      count <- 0
      for (i in max(1, x - 1):min(nrow(.self$grid), x + 1)) {
        for (j in max(1, y - 1):min(ncol(.self$grid), y + 1)) {
          if (!(i == x && j == y) && .self$grid[i, j] == 1) {
            count <- count + 1
          }
        }
      }
      return(count)
    }
  )
)

boundary_conditions <- function(grid, step_limit) {
  steps <- 0
  while (steps < step_limit) {
    grid$update()
    steps <- steps + 1
  }
}

main <- function() {
  size <- 10
  step_limit <- 100
  automata <- AutomataGrid(size = size)
  boundary_conditions(automata, step_limit)
}

main()