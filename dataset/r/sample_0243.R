library(matrixStats)

Automata <- setRefClass("Automata",
  fields = list(grid = "matrix", boundary_type = "character", size = "numeric"),
  methods = list(
    initialize = function(size, boundary_type) {
      .self$grid <- matrix(0, nrow = size, ncol = size, byrow = TRUE)
      .self$boundary_type <- boundary_type
      .self$size <- size
    },
    apply_boundary_conditions = function() {
      if (.self$boundary_type == "fixed") {
        .self$grid[, 1] <- 1
        .self$grid[, .self$size] <- 1
        .self$grid[1, ] <- 1
        .self$grid[.self$size, ] <- 1
      } else if (.self$boundary_type == "periodic") {
        .self$grid[, 1] <- .self$grid[, .self$size - 1]
        .self$grid[, .self$size] <- .self$grid[, 2]
        .self$grid[1, ] <- .self$grid[.self$size - 1, ]
        .self$grid[.self$size, ] <- .self$grid[2, ]
      }
    },
    update_grid = function() {
      new_grid <- .self$grid
      for (i in 2:(.self$size - 1)) {
        for (j in 2:(.self$size - 1)) {
          neighbors <- sum(.self$grid[(i - 1):(i + 1), (j - 1):(j + 1)]) - .self$grid[i, j]
          if (.self$grid[i, j] == 1) {
            if (neighbors < 2 || neighbors > 3) {
              new_grid[i, j] <- 0
            }
          } else if (neighbors == 3) {
            new_grid[i, j] <- 1
          }
        }
      }
      .self$grid <- new_grid
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(automata = "Automata", steps = "numeric"),
  methods = list(
    initialize = function(automata, steps) {
      .self$automata <- automata
      .self$steps <- steps
    },
    run = function() {
      for (i in 1:.self$steps) {
        .self$automata$apply_boundary_conditions()
        .self$automata$update_grid()
      }
    }
  )
)

main <- function() {
  size <- 10
  boundary_type <- "fixed"
  steps <- 50
  automata <- Automata$new(size, boundary_type)
  simulation <- Simulation$new(automata, steps)
  simulation$run()
}

main()