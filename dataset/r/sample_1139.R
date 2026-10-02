update_state <- function(grid) {
  new_grid <- lapply(grid, function(row) { return(row) })
  for (y in 1:nrow(grid)) {
    for (x in 1:ncol(grid)) {
      neighbors <- c()
      for (dy in c(-1, 0, 1)) {
        for (dx in c(-1, 0, 1)) {
          if (dy == 0 && dx == 0) {
            next
          }
          ny <- y + dy
          nx <- x + dx
          if (ny >= 1 && ny <= nrow(grid) && nx >= 1 && nx <= ncol(grid)) {
            neighbors <- c(neighbors, grid[ny, nx])
          }
        }
      }
      count <- sum(neighbors)
      if (grid[y, x] == 1 && count < 2) {
        new_grid[[y]][x] <- 0
      } else if (grid[y, x] == 1 && (count == 2 || count == 3)) {
        new_grid[[y]][x] <- 1
      } else if (grid[y, x] == 1 && count > 3) {
        new_grid[[y]][x] <- 0
      } else if (grid[y, x] == 0 && count == 3) {
        new_grid[[y]][x] <- 1
      }
    }
  }
  return(new_grid)
}

display_grid <- function(grid) {
  for (row in grid) {
    cat(paste(ifelse(row == 1, "O", " "), collapse = ""), "\n")
  }
  cat("\n")
}

simulate <- function(grid) {
  display_grid(grid)
  simulate(update_state(grid))
}

main <- function() {
  initial_grid <- matrix(c(0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0), nrow = 5, byrow = TRUE)
  simulate(initial_grid)
}

main()