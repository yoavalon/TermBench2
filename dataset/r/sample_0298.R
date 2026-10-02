library(abind)

AutomataGrid <- setRefClass("AutomataGrid",
                             fields = list(grid = "matrix", size = "numeric"),
                             methods = list(
                               initialize = function(size, density) {
                                 .self$size <- size
                                 .self$grid <- matrix(sample(c(0, 1), size^2, replace = TRUE, prob = c(1 - density, density)), nrow = size, ncol = size)
                               },
                               apply_rules = function() {
                                 new_grid <- .self$grid
                                 for (i in 2:(.self$size - 1)) {
                                   for (j in 2:(.self$size - 1)) {
                                     neighbors <- sum(.self$grid[(i - 1):(i + 1), (j - 1):(j + 1)]) - .self$grid[i, j]
                                     if (.self$grid[i, j] == 1 && (neighbors < 2 || neighbors > 3)) {
                                       new_grid[i, j] <- 0
                                     } else if (.self$grid[i, j] == 0 && neighbors == 3) {
                                       new_grid[i, j] <- 1
                                     }
                                   }
                                 }
                                 .self$grid <<- new_grid
                               },
                               set_boundary_conditions = function() {
                                 .self$grid[, 1] <<- .self$grid[, .self$size - 1]
                                 .self$grid[, .self$size] <<- .self$grid[, 2]
                                 .self$grid[1, ] <<- .self$grid[.self$size - 1, ]
                                 .self$grid[.self$size, ] <<- .self$grid[2, ]
                               }
                             ))

Simulation <- setRefClass("Simulation",
                          fields = list(grid = "AutomataGrid", steps = "numeric"),
                          methods = list(
                            initialize = function(grid, steps) {
                              .self$grid <- grid
                              .self$steps <- steps
                            },
                            run = function() {
                              for (i in 1:.self$steps) {
                                .self$grid$apply_rules()
                                .self$grid$set_boundary_conditions()
                              }
                            }
                          ))

main <- function() {
  size <- 10
  density <- 0.3
  steps <- 50
  grid <- new(AutomataGrid, size, density)
  simulation <- new(Simulation, grid, steps)
  simulation$run()
}

main()