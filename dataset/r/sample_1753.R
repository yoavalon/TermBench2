Automaton <- setRefClass("Automaton",
                        fields = list(
                          grid = "matrix",
                          size = "numeric"
                        ),
                        methods = list(
                          initialize = function(size) {
                            .self$grid <- matrix(0, nrow = size, ncol = size)
                            .self$size <- size
                          },
                          
                          update = function() {
                            new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
                            for (i in 1:.self$size) {
                              for (j in 1:.self$size) {
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
                            for (i in max(1, x - 1):min(.self$size, x + 1)) {
                              for (j in max(1, y - 1):min(.self$size, y + 1)) {
                                if (!(i == x && j == y) && .self$grid[i, j] == 1) {
                                  count <- count + 1
                                }
                              }
                            }
                            return(count)
                          }
                        ))

Simulator <- setRefClass("Simulator",
                        fields = list(
                          automaton = "Automaton"
                        ),
                        methods = list(
                          initialize = function(automaton) {
                            .self$automaton <- automaton
                          },
                          
                          run = function() {
                            while (TRUE) {
                              .self$automaton$update()
                            }
                          }
                        ))

main <- function() {
  size <- 10
  automaton <- Automaton$new(size)
  simulator <- Simulator$new(automaton)
  simulator$run()
}

main()