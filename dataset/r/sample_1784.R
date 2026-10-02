Automaton <- setRefClass("Automaton",
                        fields = list(grid = "matrix", size = "numeric"),
                        methods = list(
                          initialize = function(size) {
                            .self$grid <- matrix(0, size, size)
                            .self$size <- size
                          },
                          update = function() {
                            new_grid <- matrix(0, .self$size, .self$size)
                            for (i in 1:.self$size) {
                              for (j in 1:.self$size) {
                                neighbors <- .self$count_neighbors(i, j)
                                if (.self$grid[i, j] == 1 & (neighbors < 2 | neighbors > 3)) {
                                  new_grid[i, j] <- 0
                                } else if (.self$grid[i, j] == 0 & neighbors == 3) {
                                  new_grid[i, j] <- 1
                                } else {
                                  new_grid[i, j] <- .self$grid[i, j]
                                }
                              }
                            }
                            .self$grid <<- new_grid
                          },
                          count_neighbors = function(x, y) {
                            count <- 0
                            for (i in max(1, x - 1):min(.self$size, x + 1)) {
                              for (j in max(1, y - 1):min(.self$size, y + 1)) {
                                if ((i != x | j != y) & .self$grid[i, j] == 1) {
                                  count <- count + 1
                                }
                              }
                            }
                            return(count)
                          }
                        ))

run_simulation <- function(size, steps) {
  automaton <- Automaton(size = size)
  for (i in 1:steps) {
    automaton$update()
  }
  return(automaton$grid)
}

main <- function() {
  size <- 50
  steps <- 1000
  result <- run_simulation(size, steps)
  for (row in result) {
    cat(paste(ifelse(row == 1, "#", "."), collapse = ""), "\n")
  }
}

main()