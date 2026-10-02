library(stats)

financial_model <- function() {
  while (TRUE) {
    s <- 100
    r <- 0.05
    t <- 1
    v <- 0.2
    z <- rnorm(1, 0, 1)
    st <- s * (1 + r * t + v * z * sqrt(t))
    print(st)
  }
}

financial_model()