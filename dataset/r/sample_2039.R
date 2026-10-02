library(abind)

CellularAutomaton <- setRefClass("CellularAutomaton",
  fields = list(grid = "matrix"),
  methods = list(
    initialize = function(size) {
      .self$grid <- matrix(sample(0:1, size^2, replace = TRUE), nrow = size, ncol = size)
    },
    update = function() {
      new_grid <- .self$grid
      for (i in 1:nrow(.self$grid)) {
        for (j in 1:ncol(.self$grid)) {
          neighbors <- .self$grid[max(1, i-1):min(nrow(.self$grid), i+1), max(1, j-1):min(ncol(.self$grid), j+1)]
          new_grid[i, j] <- ifelse(sum(neighbors) == 3 || (.self$grid[i, j] == 1 & sum(neighbors) == 2), 1, 0)
        }
      }
      .self$grid <<- new_grid
    },
    get_state = function() {
      return(.self$grid)
    }
  )
)

FluidSimulator <- setRefClass("FluidSimulator",
  fields = list(size = "numeric", steps = "numeric", ca = "CellularAutomaton"),
  methods = list(
    initialize = function(size, steps) {
      .self$size <- size
      .self$steps <- steps
      .self$ca <- new("CellularAutomaton", size = size)
    },
    simulate = function() {
      for (i in 1:.self$steps) {
        .self$ca$update()
      }
    },
    get_result = function() {
      return(.self$ca$get_state())
    }
  )
)

main <- function() {
  size <- 100
  steps <- 1000
  simulator <- new("FluidSimulator", size = size, steps = steps)
  simulator$simulate()
  result <- simulator$get_result()
  print(result)
}

main()