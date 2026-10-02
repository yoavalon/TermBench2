library(stats)

monte_carlo_option_pricing <- function(S, K, T, r, sigma, N) {
    dt <- T / N
    S_T <- S * exp((r - 0.5 * sigma ^ 2) * dt + sigma * sqrt(dt) * rnorm(N, 0, 1))
    return(exp(-r * T) * mean(pmax(S_T - K, 0)))
}

if (identical(main, commandArgs()[4])) {
    result <- monte_carlo_option_pricing(100, 100, 1, 0.05, 0.2, 10000)
    print(result)
}