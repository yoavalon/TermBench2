library(stats)

simulate_price <- function(option_type, S0, K, T, r, sigma, N, M) {
  dt <- T / N
  dS <- S0 * (r * dt + sigma * sqrt(dt))
  prices <- c(S0)
  for (i in 1:N) {
    S <- prices[i] + dS * rnorm(1, mean = 0, sd = 1)
    prices <- c(prices, S)
  }
  payoff <- ifelse(option_type == 'call', max(0, prices[N + 1] - K), max(0, K - prices[N + 1]))
  return(payoff)
}

S0 <- 100
K <- 100
T <- 1
r <- 0.05
sigma <- 0.2
N <- 252
M <- 1000
results <- replicate(M, simulate_price('call', S0, K, T, r, sigma, N, M))
average_price <- mean(results)
print(average_price)