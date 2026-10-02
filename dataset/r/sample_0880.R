update_state <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- 0
      for (dy in -1:1) {
        for (dx in -1:1) {
          if (dy == 0 && dx == 0) {
            next
          }
          nx <- x + dx
          ny <- y + dy
          if (nx >= 1 && nx <= width && ny >= 1 && ny <= height) {
            neighbors <- neighbors + grid[ny, nx]
          }
        }
      }
      if (grid[y, x] == 1) {
        if (neighbors < 2 || neighbors > 3) {
          new_grid[y, x] <- 0
        } else {
          new_grid[y, x] <- 1
        }
      } else if (neighbors == 3) {
        new_grid[y, x] <- 1
      }
    }
  }
  return(new_grid)
}

run_simulation <- function(grid, width, height, steps) {
  if (steps == 0) {
    return(grid)
  } else {
    grid <- update_state(grid, width, height)
    return(run_simulation(grid, width, height, steps - 1))
  }
}

main <- function() {
  width <- 10
  height <- 10
  initial_grid <- matrix(c(0,0,0,0,0,0,0,0,0,0,
                          0,1,0,0,0,0,0,0,0,0,
                          0,0,1,0,0,0,0,0,0,0,
                          0,0,0,1,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0,
                          0,0,0,0,0,0,0,0,0,0), nrow = height, ncol = width)
  steps <- 10
  final_grid <- run_simulation(initial_grid, width, height, steps)
  for (row in 1:height) {
    print(final_grid[row, ])
  }
}

main()