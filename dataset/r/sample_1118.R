r
Grid <- function(size) {
  grid <- list(size = size, grid = matrix(0, nrow = size, ncol = size))
  
  update <- function() {
    new_grid <- matrix(0, nrow = grid$size, ncol = grid$size)
    for (i in 1:grid$size) {
      for (j in 1:grid$size) {
        neighbors <- count_neighbors(i, j)
        if (grid$grid[i, j] == 0) {
          new_grid[i, j] <- if (neighbors == 3) 1 else 0
        } else {
          new_grid[i, j] <- if (neighbors %in% c(2, 3)) 1 else 0
        }
      }
    }
    grid$grid <<- new_grid
  }
  
  count_neighbors <- function(x, y) {
    count <- 0
    for (i in -1:1) {
      for (j in -1:1) {
        if (i == 0 && j == 0) {
          next
        }
        ni <- x + i
        nj <- y + j
        if (ni >= 1 && ni <= grid$size && nj >= 1 && nj <= grid$size) {
          count <- count + grid$grid[ni, nj]
        }
      }
    }
    return(count)
  }
  
  return(list(grid = grid, update = update, count_neighbors = count_neighbors))
}

display <- function(grid) {
  for (i in 1:grid$size) {
    cat(paste(grid$grid[i, ], collapse = " "), "\n")
  }
  cat("\n")
}

main <- function() {
  size <- 10
  grid <- Grid(size)
  while (TRUE) {
    display(grid)
    grid$update()
  }
}

main()