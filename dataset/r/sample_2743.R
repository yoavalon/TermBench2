library(stats)

monte_carlo_pricing <- function(S0, K, T, r, sigma, N) {
  dt <- T / N
  S <- numeric(N + 1)
  S[1] <- S0
  for (t in 2:(N + 1)) {
    S[t] <- S[t - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(1))
  }
  return(exp(-r * T) * pmax(S[N + 1] - K, 0))
}

main <- function() {
  while (TRUE) {
    result <- monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 252)
    print(result)
  }
}

main()