library(stats)

financial_model <- function(T, N, S0, K, r, sigma) {
  dt <- T / N
  S <- matrix(0, nrow = N + 1, ncol = N + 1)
  S[1, 1] <- S0
  for (i in 2:(N + 1)) {
    for (j in 1:i) {
      if (j > 1) {
        S[i, j] <- S[i - 1, j - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * rnorm(1))
      } else {
        S[i, j] <- 0
      }
    }
  }
  payoff <- pmax(S[N + 1, ] - K, 0)
  option_price <- exp(-r * T) * mean(payoff)
  return(option_price)
}

result <- financial_model(1, 100, 100, 100, 0.05, 0.2)
print(result)