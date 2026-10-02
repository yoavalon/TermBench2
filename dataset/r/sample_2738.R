cellular_automata <- function() {
  grid <- matrix(c(0, 1, 0, 0, 1, 0, 0, 1, 0), nrow = 3, byrow = TRUE)
  while (TRUE) {
    new_grid <- matrix(0, nrow = 3, ncol = 3)
    for (i in 1:3) {
      for (j in 1:3) {
        live_neighbors <- 0
        for (x in i - 1:i + 1) {
          for (y in j - 1:j + 1) {
            if (x >= 1 && x <= 3 && y >= 1 && y <= 3 && !(x == i && y == j) && grid[x, y] == 1) {
              live_neighbors <- live_neighbors + 1
            }
          }
        }
        new_grid[i, j] <- ifelse(live_neighbors == 2, 1, 0)
      }
    }
    grid <- new_grid
  }
}

cellular_automata()