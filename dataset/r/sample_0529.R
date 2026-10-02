Grid <- setRefClass("Grid", fields = list(grid = "matrix"),
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
                       .self$grid <<- new_grid
                     },
                     count_neighbors = function(x, y) {
                       count <- 0
                       for (i in x - 1:x + 1) {
                         for (j in y - 1:y + 1) {
                           if ((i != x || j != y) && i >= 1 && i <= nrow(.self$grid) && j >= 1 && j <= ncol(.self$grid)) {
                             count <- count + .self$grid[i, j]
                           }
                         }
                       }
                       return(count)
                     }
                   ))

Simulation <- setRefClass("Simulation", fields = list(grid = "Grid"),
                          methods = list(
                            initialize = function(grid_size) {
                              .self$grid <<- Grid(grid_size)
                            },
                            run = function() {
                              while (TRUE) {
                                .self$grid$update()
                              }
                            }
                          ))

main <- function() {
  simulation <- Simulation(10)
  simulation$run()
}

main()