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
        new_grid[y, x] <- ifelse(2 <= neighbors && neighbors <= 3, 1, 0)
      } else {
        new_grid[y, x] <- ifelse(neighbors == 3, 1, 0)
      }
    }
  }
  return(new_grid)
}

simulate <- function(grid, width, height, steps) {
  if (steps == 0) {
    return(grid)
  } else {
    return(simulate(update_state(grid, width, height), width, height, steps - 1))
  }
}

main <- function() {
  width <- 50
  height <- 50
  steps <- 100
  grid <- matrix(0, nrow = height, ncol = width)
  for (y in 1:height) {
    for (x in 1:width) {
      grid[y, x] <- ifelse((x + y) %% 2 == 1, 1, 0)
    }
  }
  final_grid <- simulate(grid, width, height, steps)
  for (row in 1:nrow(final_grid)) {
    cat(paste(ifelse(final_grid[row, ] == 1, "O", " "), collapse = ""), "\n")
  }
}

main()