r
update_grid <- function(grid) {
  rows <- nrow(grid)
  cols <- ncol(grid)
  new_grid <- matrix(0, nrow = rows, ncol = cols)
  for (i in 1:rows) {
    for (j in 1:cols) {
      neighbors <- sum(grid[max(1, i - 1):min(rows, i + 1), max(1, j - 1):min(cols, j + 1)], na.rm = TRUE) - grid[i, j]
      if ((grid[i, j] == 1 && neighbors %in% c(2, 3)) || (grid[i, j] == 0 && neighbors == 3)) {
        new_grid[i, j] <- 1
      }
    }
  }
  return(new_grid)
}

main <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    grid <- update_grid(grid)
    for (row in 1:nrow(grid)) {
      cat(paste0(ifelse(grid[row, ] == 1, '█', ' '), collapse = ''), "\n")
    }
    cat("\n")
  }
}

main()