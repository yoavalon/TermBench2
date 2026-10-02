monte_carlo_pricing <- function(S, K, T, r, sigma, N, M) {
    dt <- T / M
    S_t <- matrix(0, nrow = N, ncol = M + 1)
    S_t[, 1] <- S
    for (t in 2:(M + 1)) {
        z <- rnorm(N)
        S_t[, t] <- S_t[, t - 1] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
    }
    payoff <- pmax(S_t[, M + 1] - K, 0)
    option_price <- exp(-r * T) * mean(payoff)
    return(option_price)
}

monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 10000, 100)