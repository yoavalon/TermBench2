library(stats)

calculate_price <- function(option_type, S, K, T, r, sigma, n) {
  if (n == 0) {
    if (option_type == 'call') {
      return(max(S - K, 0))
    } else {
      return(max(K - S, 0))
    }
  } else {
    d1 <- (log(S / K) + (r + 0.5 * sigma^2) * T) / (sigma * sqrt(T))
    d2 <- d1 - sigma * sqrt(T)
    if (option_type == 'call') {
      price <- S * exp(-r * T) * pnorm(d1) - K * exp(-r * T) * pnorm(d2)
    } else {
      price <- K * exp(-r * T) * pnorm(-d2) - S * exp(-r * T) * pnorm(-d1)
    }
    return(price)
  }
}

norm_cdf <- function(x) {
  return(0.5 * (1 + pnorm(x / sqrt(2))))
}

monte_carlo_simulation <- function(option_type, S, K, T, r, sigma, N, n) {
  total_price <- 0
  for (i in 1:N) {
    S_T <- S
    for (j in 1:n) {
      z <- rnorm(1, 0, 1)
      S_T <- S_T * exp((r - 0.5 * sigma^2) * T / n + sigma * sqrt(T / n) * z)
    }
    total_price <- total_price + calculate_price(option_type, S_T, K, T, r, sigma, 0)
  }
  return(total_price / N)
}

main <- function() {
  S <- 100
  K <- 100
  T <- 1
  r <- 0.05
  sigma <- 0.2
  N <- 10000
  n <- 10
  option_type <- 'call'
  result <- monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n)
  print(result)
}

main()