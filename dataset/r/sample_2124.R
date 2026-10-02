cellular_automata <- function(n) {
  a <- matrix(0, n, n)
  while (TRUE) {
    b <- matrix(0, n, n)
    for (i in 1:n) {
      for (j in 1:n) {
        b[i, j] <- (a[i, j] + a[[(i - 1) %% n + 1], j] + a[i, [(j - 1) %% n + 1]] + a[[(i + 1) %% n + 1], j] + a[i, [(j + 1) %% n + 1]]) / 5
      }
    }
    a <- b
  }
}

cellular_automata(10)