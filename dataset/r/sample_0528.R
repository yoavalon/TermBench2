library(abind)

Automaton <- setRefClass("Automaton",
  fields = list(
    grid = "matrix",
    size = "numeric"
  ),
  methods = list(
    initialize = function(size) {
      .self$size <- size
      .self$grid <- matrix(0, nrow = size, ncol = size)
    },
    update = function() {
      new_grid <- .self$grid
      for (i in 1:.self$size) {
        for (j in 1:.self$size) {
          neighbors <- .self$grid[(i - 1) %% .self$size + 1, (j - 1) %% .self$size + 1] + 
                      .self$grid[(i - 1) %% .self$size + 1, j] + 
                      .self$grid[(i - 1) %% .self$size + 1, (j + 1) %% .self$size + 1] + 
                      .self$grid[i, (j - 1) %% .self$size + 1] + 
                      .self$grid[i, (j + 1) %% .self$size + 1] + 
                      .self$grid[(i + 1) %% .self$size + 1, (j - 1) %% .self$size + 1] + 
                      .self$grid[(i + 1) %% .self$size + 1, j] + 
                      .self$grid[(i + 1) %% .self$size + 1, (j + 1) %% .self$size + 1]
          if (.self$grid[i, j] == 1 & (neighbors < 2 | neighbors > 3)) {
            new_grid[i, j] <- 0
          } else if (.self$grid[i, j] == 0 & neighbors == 3) {
            new_grid[i, j] <- 1
          }
        }
      }
      .self$grid <<- new_grid
    }
  )
)

BoundaryHandler <- setRefClass("BoundaryHandler",
  fields = list(
    automaton = "Automaton"
  ),
  methods = list(
    initialize = function(automaton) {
      .self$automaton <- automaton
    },
    apply_boundary_conditions = function() {
      .self$automaton$grid[1, ] <<- 0
      .self$automaton$grid[nrow(.self$automaton$grid), ] <<- 0
      .self$automaton$grid[, 1] <<- 0
      .self$automaton$grid[, ncol(.self$automaton$grid)] <<- 0
    }
  )
)

main <- function() {
  size <- 100
  automaton <- Automaton$new(size)
  boundary_handler <- BoundaryHandler$new(automaton)
  automaton$grid[1, 2] <<- 1
  automaton$grid[2, 3] <<- 1
  automaton$grid[3, 1] <<- 1
  automaton$grid[3, 2] <<- 1
  automaton$grid[3, 3] <<- 1
  while (TRUE) {
    boundary_handler$apply_boundary_conditions()
    automaton$update()
  }
}

main()