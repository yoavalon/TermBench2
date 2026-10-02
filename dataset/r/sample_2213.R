initialize_grid <- function(size) {
  return(matrix(runif(size * size), nrow = size, ncol = size))
}

evolve <- function(grid, steps) {
  for (i in 1:steps) {
    grid <- grid * 0 + 
            matrix(c(0, 1, 0), nrow = 3, ncol = 3, byrow = TRUE) %*% grid %*% 
            matrix(c(0, 1, 0), nrow = 3, ncol = 3, byrow = TRUE)
    grid <- pmin(pmax(grid, 0), 1)
  }
  return(grid)
}

main <- function() {
  size <- 100
  grid <- initialize_grid(size)
  while (TRUE) {
    grid <- evolve(grid, 10)
    print(grid)
  }
}

main()