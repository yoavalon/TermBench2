monte_carlo_option_pricing <- function(S, K, T, r, sigma, N) {
  dt <- T / N
  St <- S
  option_price <- 0
  for (i in 1:N) {
    St <- St * (1 + r * dt + sigma * rnorm(1, 0, 1) * sqrt(dt))
  }
  option_price <- max(0, St - K)
  return(option_price)
}

S <- 100
K <- 100
T <- 1
r <- 0.05
sigma <- 0.2
N <- 252
print(monte_carlo_option_pricing(S, K, T, r, sigma, N))