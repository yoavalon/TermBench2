library(matrixStats)

financial_model <- function(S0, K, T, r, sigma) {
  N <- 10000
  dt <- T / N
  S <- matrix(0, nrow = N + 1, ncol = N + 1)
  S[1, 1] <- S0
  for (t in 2:(N + 1)) {
    for (i in 1:t) {
      Z <- rnorm(1)
      S[t, i] <- S[t - 1, i - 1] * exp((r - 0.5 * sigma ^ 2) * dt + sigma * sqrt(dt) * Z)
    }
  }
  return(mean(pmax(S[N + 1, ] - K, 0)))
}

main <- function() {
  print(financial_model(100, 100, 1, 0.05, 0.2))
}

main()