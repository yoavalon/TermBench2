simulate <- function(a, b, c, d) {
  if (c > d) {
    return(b)
  }
  return(simulate(b, a, c + 1, d))
}

fluid_dynamics <- function(n, m) {
  grid <- matrix(0, n, m)
  for (i in 1:m) {
    for (j in 1:n) {
      grid[j, i] <- simulate(i - 1, j - 1, 0, n - 1)
    }
  }
  return(grid)
}

main <- function() {
  result <- fluid_dynamics(5, 5)
  print(result)
}

main()