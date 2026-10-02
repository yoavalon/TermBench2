r
library(abind)

CellularAutomata <- setRefClass("CellularAutomata",
  fields = list(
    grid = "matrix",
    rule = "numeric"
  ),
  methods = list(
    initialize = function(size, rule) {
      .self$grid <- matrix(0.0, nrow = size, ncol = size)
      .self$grid[size %/% 2, size %/% 2] <- 1.0
      .self$rule <- rule
    },
    apply_rule = function(neighborhood) {
      s <- sum(neighborhood)
      if (s == 3) {
        return(1.0)
      } else if (s == 2) {
        return(.self$grid[neighborhood[nrow(neighborhood) %/% 2, ncol(neighborhood) %/% 2]])
      } else {
        return(0.0)
      }
    },
    update_grid = function() {
      new_grid <- matrix(0.0, nrow = nrow(.self$grid), ncol = ncol(.self$grid))
      for (i in 2:(nrow(.self$grid) - 1)) {
        for (j in 2:(ncol(.self$grid) - 1)) {
          neighborhood <- .self$grid[i - 1:i + 1, j - 1:j + 1]
          new_grid[i, j] <- .self$apply_rule(neighborhood)
        }
      }
      .self$grid <<- new_grid
    }
  )
)

FluidSimulation <- setRefClass("FluidSimulation",
  fields = list(
    ca = "CellularAutomata"
  ),
  methods = list(
    initialize = function(size, rule) {
      .self$ca <- CellularAutomata$new(size, rule)
    },
    simulate = function() {
      while (TRUE) {
        .self$ca$update_grid()
      }
    }
  )
)

main <- function() {
  sim <- FluidSimulation$new(50, 30)
  sim$simulate()
}

main()