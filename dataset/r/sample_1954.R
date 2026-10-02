update_grid <- function(grid, width, height) {
  new_grid <- matrix(0.0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      neighbors <- 0.0
      for (dy in -1:1) {
        for (dx in -1:1) {
          if (dx == 0 && dy == 0) {
            next
          }
          nx <- x + dx
          ny <- y + dy
          if (nx >= 1 && nx <= width && ny >= 1 && ny <= height) {
            neighbors <- neighbors + grid[ny, nx]
          }
        }
      }
      new_grid[y, x] <- grid[y, x] + 0.1 * (neighbors - 2.0 * grid[y, x])
    }
  }
  return(new_grid)
}

main <- function() {
  width <- 10
  height <- 10
  grid <- matrix(0.0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      if (x == y) {
        grid[y, x] <- 0.0
      } else {
        grid[y, x] <- 1.0
      }
    }
  }
  for (i in 1:100) {
    grid <- update_grid(grid, width, height)
  }
  print(grid)
}

main()