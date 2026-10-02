update_state <- function(grid, x, y, size) {
  if (x < 0 || x >= size || y < 0 || y >= size) {
    return(grid)
  }
  neighbors <- 0
  for (i in -1:1) {
    for (j in -1:1) {
      if (i == 0 && j == 0) {
        next
      }
      nx <- x + i
      ny <- y + j
      if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
        neighbors <- neighbors + grid[nx + 1, ny + 1]
      }
    }
  }
  if (grid[x + 1, y + 1] == 1) {
    if (neighbors < 2 || neighbors > 3) {
      grid[x + 1, y + 1] <- 0
    }
  } else if (neighbors == 3) {
    grid[x + 1, y + 1] <- 1
  }
  if (x < size - 1) {
    return(update_state(grid, x + 1, y, size))
  } else if (y < size - 1) {
    return(update_state(grid, 0, y + 1, size))
  } else {
    return(grid)
  }
}

main <- function() {
  size <- 10
  grid <- matrix(0, nrow = size, ncol = size)
  grid[(size %/% 2) + 1, (size %/% 2) + 1] <- 1
  while (TRUE) {
    grid <- update_state(grid, 0, 0, size)
  }
}

main()