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
                                if (.self$grid[i, j] == 0) {
                                  if (neighbors == 3) {
                                    new_grid[i, j] <- 1
                                  }
                                } else if (neighbors < 2 | neighbors > 3) {
                                  new_grid[i, j] <- 0
                                } else {
                                  new_grid[i, j] <- 1
                                }
                              }
                            }
                            .self$grid <<- new_grid
                          },
                          count_neighbors = function(x, y) {
                            count <- 0
                            for (i in -1:1) {
                              for (j in -1:1) {
                                if (i == 0 & j == 0) {
                                  next
                                }
                                ni <- x + i
                                nj <- y + j
                                if (ni >= 1 & ni <= .self$size & nj >= 1 & nj <= .self$size) {
                                  count <- count + .self$grid[ni, nj]
                                }
                              }
                            }
                            return(count)
                          }
                        ))

display <- function(grid) {
  for (row in 1:nrow(grid)) {
    cat(paste(ifelse(grid[row, ] == 1, "#", " "), collapse = ""), "\n")
  }
}

main <- function() {
  size <- 10
  automaton <- Automaton(size = size)
  automaton$grid[5, 5] <- 1
  automaton$grid[5, 6] <- 1
  automaton$grid[6, 5] <- 1
  automaton$grid[6, 6] <- 1
  while (TRUE) {
    display(automaton$grid)
    automaton$update()
  }
}

main()