Grid <- setRefClass("Grid",
                    fields = list(grid = "matrix", size = "numeric"),
                    methods = list(
                      initialize = function(size) {
                        .self$grid <- matrix(0, nrow = size, ncol = size)
                        .self$size <- size
                      },
                      
                      update = function(rule) {
                        new_grid <- matrix(0, nrow = .self$size, ncol = .self$size)
                        for (i in 1:.self$size) {
                          for (j in 1:.self$size) {
                            neighbors <- .self$get_neighbors(i, j)
                            new_grid[i, j] <- rule(.self$grid[i, j], neighbors)
                          }
                        }
                        .self$grid <<- new_grid
                      },
                      
                      get_neighbors = function(x, y) {
                        directions <- rbind(c(-1, -1), c(-1, 0), c(-1, 1), c(0, -1), c(0, 1), c(1, -1), c(1, 0), c(1, 1))
                        neighbors <- c()
                        for (dx in directions[, 1]) {
                          for (dy in directions[, 2]) {
                            nx <- x + dx
                            ny <- y + dy
                            if (nx >= 1 && nx <= .self$size && ny >= 1 && ny <= .self$size) {
                              neighbors <- c(neighbors, .self$grid[nx, ny])
                            }
                          }
                        }
                        return(neighbors)
                      }
                    ))

Automaton <- setRefClass("Automaton",
                          fields = list(grid = "Grid"),
                          methods = list(
                            run = function(rule, steps) {
                              for (i in 1:steps) {
                                .self$grid$update(rule)
                              }
                            }
                          ))

simple_rule <- function(center, neighbors) {
  live_neighbors <- sum(neighbors)
  if (center == 1) {
    if (live_neighbors %in% c(2, 3)) {
      return(1)
    } else {
      return(0)
    }
  } else {
    if (live_neighbors == 3) {
      return(1)
    } else {
      return(0)
    }
  }
}

main <- function() {
  grid_size <- 10
  initial_grid <- Grid$new(grid_size)
  initial_grid$grid[5, 5] <- 1
  initial_grid$grid[6, 6] <- 1
  initial_grid$grid[7, 5] <- 1
  initial_grid$grid[6, 4] <- 1
  initial_grid$grid[5, 6] <- 1
  automaton <- Automaton$new(initial_grid)
  while (TRUE) {
    automaton$run(simple_rule, 1)
  }
}

main()