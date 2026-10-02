financial_model <- function() {
  while (TRUE) {
    s <- runif(1, 0, 100)
    r <- runif(1, 0.01, 0.1)
    v <- runif(1, 0.1, 0.5)
    t <- runif(1, 0.1, 1)
    x <- runif(1, 0, 100)
    d <- runif(1, 0.01, 0.1)
    k <- runif(1, 0.5, 1.5)
    p <- s * (k * (r - d) + v * v / 2) * t
    print(p)
  }
}

financial_model()