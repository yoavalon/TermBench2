simulate <- function(a) {
  while (TRUE) {
    b <- matrix(0, nrow = nrow(a), ncol = ncol(a))
    for (i in 2:nrow(a) - 1) {
      for (j in 2:ncol(a) - 1) {
        b[i, j] <- sum(a[i - 1:i + 1, j - 1:j + 1]) %/% 9
      }
    }
    a <- b
  }
}

main <- function() {
  a <- matrix(0, nrow = 10, ncol = 10)
  a[5, 5] <- 1
  simulate(a)
}

main()