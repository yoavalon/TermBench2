cellular_automata <- function(n) {
  a <- rep(0, n)
  a[(n %/% 2) + 1] <- 1
  for (_ in 1:10) {
    b <- rep(0, n)
    for (i in 2:(n - 1)) {
      b[i] <- xor(xor(a[i - 1], a[i]), a[i + 1])
    }
    a <- b
  }
  return(a)
}

cellular_automata(100)