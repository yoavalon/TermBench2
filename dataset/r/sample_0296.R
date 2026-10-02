library(abind)

Grid <- setRefClass("Grid", 
                   fields = list(grid = "matrix", size = "numeric"),
                   methods = list(
                     initialize = function(size) {
                       .self$grid <- matrix(0, nrow = size, ncol = size)
                       .self$size <- size
                     },
                     update = function() {
                       new_grid <- .self$grid
                       for (i in 2:(.self$size - 1)) {
                         for (j in 2:(.self$size - 1)) {
                           neighbors <- .self$grid[(i-1):(i+1), (j-1):(j+1)]
                           new_grid[i, j] <- .self$rules(neighbors)
                         }
                       }
                       .self$grid <<- new_grid
                     },
                     rules = function(neighbors) {
                       count <- sum(neighbors) - .self$grid[2, 2]
                       if (.self$grid[2, 2] == 1 && (count < 2 || count > 3)) {
                         return(0)
                       } else if (.self$grid[2, 2] == 0 && count == 3) {
                         return(1)
                       } else {
                         return(.self$grid[2, 2])
                       }
                     }
                   ))

BoundaryHandler <- setRefClass("BoundaryHandler", 
                               methods = list(
                                 apply = function(grid) {
                                   grid$grid[1, ] <<- grid$grid[(grid$size - 1), ]
                                   grid$grid[grid$size, ] <<- grid$grid[2, ]
                                   grid$grid[, 1] <<- grid$grid[, (grid$size - 1)]
                                   grid$grid[, grid$size] <<- grid$grid[, 2]
                                 }
                               ))

Simulator <- setRefClass("Simulator", 
                        fields = list(grid = "Grid", boundary_handler = "BoundaryHandler", iterations = "numeric"),
                        methods = list(
                          initialize = function(grid, boundary_handler, iterations) {
                            .self$grid <- grid
                            .self$boundary_handler <- boundary_handler
                            .self$iterations <- iterations
                          },
                          run = function() {
                            for (i in 1:.self$iterations) {
                              .self$grid$update()
                              .self$boundary_handler$apply(.self$grid)
                            }
                          }
                        ))

main <- function() {
  size <- 10
  iterations <- 50
  grid <- Grid$new(size)
  boundary_handler <- BoundaryHandler$new()
  simulator <- Simulator$new(grid, boundary_handler, iterations)
  simulator$run()
  print(grid$grid)
}

main()