financial_simulation <- function() {
  library(stats)
  r <- 0.05
  s <- 100
  t <- 1
  v <- 0.2
  while (TRUE) {
    z <- rnorm(1, 0, 1)
    s <- s * (1 + r - 0.5 * v^2 + v * z)
    print(s)
  }
}

financial_simulation()