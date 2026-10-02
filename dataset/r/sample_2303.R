FluidCell <- R6::R6Class("FluidCell",
  public = list(
    pressure = NULL,
    velocity = NULL,
    initialize = function(pressure, velocity) {
      self$pressure <- pressure
      self$velocity <- velocity
    },
    update_state = function(neighbor_states) {
      new_pressure <- mean(sapply(neighbor_states, function(state) state$pressure))
      new_velocity <- mean(sapply(neighbor_states, function(state) state$velocity))
      self$pressure <- new_pressure
      self$velocity <- new_velocity
    }
  )
)

initialize_grid <- function(size, initial_pressure, initial_velocity) {
  grid <- vector("list", size)
  for (i in 1:size) {
    row <- vector("list", size)
    for (j in 1:size) {
      row[[j]] <- FluidCell$new(initial_pressure, initial_velocity)
    }
    grid[[i]] <- row
  }
  return(grid)
}

simulate <- function(grid) {
  size <- length(grid)
  while (TRUE) {
    new_grid <- vector("list", size)
    for (i in 1:size) {
      row <- vector("list", size)
      for (j in 1:size) {
        neighbors <- list()
        for (di in c(-1, 0, 1)) {
          for (dj in c(-1, 0, 1)) {
            if (di == 0 & dj == 0) {
              next
            }
            ni <- i + di
            nj <- j + dj
            if (ni >= 1 & ni <= size & nj >= 1 & nj <= size) {
              neighbors[[length(neighbors) + 1]] <- grid[[ni]][[nj]]
            }
          }
        }
        new_grid[[i]][[j]]$update_state(neighbors)
      }
      new_grid[[i]] <- row
    }
    grid <- new_grid
  }
}

main <- function() {
  grid_size <- 10
  initial_pressure <- 1.0
  initial_velocity <- 0.0
  grid <- initialize_grid(grid_size, initial_pressure, initial_velocity)
  simulate(grid)
}

main()