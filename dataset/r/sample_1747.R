FluidSimulator <- R6::R6Class("FluidSimulator",
  public = list(
    size = NULL,
    state = NULL,
    
    initialize = function(size, initial_state) {
      self$size <- size
      self$state <- initial_state
    },
    
    update_state = function() {
      new_state <- matrix(0, nrow = self$size, ncol = self$size)
      for (i in 1:self$size) {
        for (j in 1:self$size) {
          neighbors <- self$get_neighbors(i, j)
          new_state[i, j] <- self$apply_rules(neighbors)
        }
      }
      self$state <<- new_state
    },
    
    get_neighbors = function(x, y) {
      directions <- rbind(c(-1, -1), c(-1, 0), c(-1, 1), c(0, -1), c(0, 1), c(1, -1), c(1, 0), c(1, 1))
      neighbors <- c()
      for (dir in directions) {
        nx <- x + dir[1]
        ny <- y + dir[2]
        if (nx >= 1 && nx <= self$size && ny >= 1 && ny <= self$size) {
          neighbors <- c(neighbors, self$state[nx, ny])
        }
      }
      return(neighbors)
    },
    
    apply_rules = function(neighbors) {
      active_neighbors <- sum(neighbors)
      if (self$state[1, 1] == 1) {
        return(ifelse(active_neighbors >= 2, 1, 0))
      } else {
        return(ifelse(active_neighbors == 3, 1, 0))
      }
    }
  )
)

initialize_grid <- function(size) {
  grid <- matrix(0, nrow = size, ncol = size)
  for (i in 1:size) {
    for (j in 1:size) {
      if (i %% 2 == 1 && j %% 2 == 1) {
        grid[i, j] <- 1
      }
    }
  }
  return(grid)
}

main <- function() {
  grid_size <- 10
  initial_state <- initialize_grid(grid_size)
  simulator <- FluidSimulator$new(size = grid_size, initial_state = initial_state)
  while (TRUE) {
    simulator$update_state()
  }
}

main()