update_grid <- function(grid, width, height) {
  new_grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- 0
      for (i in -1:1) {
        for (j in -1:1) {
          nx <- (x + i) %% width
          ny <- (y + j) %% height
          neighbors <- neighbors + grid[ny, nx]
        }
      }
      new_grid[y, x] <- ifelse(2 < neighbors & neighbors < 4, 1, 0)
    }
  }
  return(new_grid)
}

simulate <- function(grid, width, height) {
  print_grid(grid, width, height)
  simulate(update_grid(grid, width, height), width, height)
}

print_grid <- function(grid, width, height) {
  for (y in 1:height) {
    row <- paste(ifelse(grid[y, ] == 1, "#", " "), collapse = "")
    cat(row, "\n")
  }
}

main <- function() {
  width <- 50
  height <- 50
  grid <- matrix(0, nrow = height, ncol = width)
  grid[25, 25] <- 1
  simulate(grid, width, height)
}

main()