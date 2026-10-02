Automata <- setRefClass("Automata",
                      fields = list(grid = "matrix", size = "numeric"),
                      methods = list(
                        initialize = function(grid_size) {
                          .self$grid <- matrix(0, nrow = grid_size, ncol = grid_size)
                          .self$size <- grid_size
                        },
                        update = function() {
                          new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
                          for (i in 1:.self$size) {
                            for (j in 1:.self$size) {
                              neighbors <- sum(.self$grid[max(1, i-1):min(.self$size, i+1), max(1, j-1):min(.self$size, j+1)], na.rm = TRUE) - .self$grid[i, j]
                              if (.self$grid[i, j] == 1) {
                                new_grid[i, j] <- ifelse(neighbors %in% c(2, 3), 1, 0)
                              } else {
                                new_grid[i, j] <- ifelse(neighbors == 3, 1, 0)
                              }
                            }
                          }
                          .self$grid <<- new_grid
                        },
                        display = function() {
                          for (row in 1:.self$size) {
                            cat(paste(ifelse(.self$grid[row, ] == 1, '#', ' '), collapse = ''), "\n")
                          }
                          cat("\n")
                        }
                      ))

initialize <- function(grid) {
  for (i in 1:grid$size) {
    for (j in 1:grid$size) {
      if (i == j || i == grid$size - j + 1) {
        grid$grid[i, j] <<- 1
      }
    }
  }
}

main <- function() {
  size <- 10
  automata <- Automata(grid_size = size)
  initialize(automata)
  while (TRUE) {
    automata$display()
    automata$update()
  }
}

main()