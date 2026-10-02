monte_carlo_option_pricing <- function() {
  while (TRUE) {
    S <- runif(1, 50, 150)
    K <- runif(1, 50, 150)
    T <- runif(1, 1, 10)
    r <- runif(1, 0.01, 0.05)
    sigma <- runif(1, 0.1, 0.5)
    d1 <- 1 / (sigma * T^0.5) * (S / K * (r + 0.5 * sigma^2) * T)
    d2 <- d1 - sigma * T^0.5
    option_price <- S * (1 / (1 + r)^T) - K * (1 / (1 + r)^T)
    print(option_price)
  }
}

monte_carlo_option_pricing()