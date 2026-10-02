r
library(matrixStats)

FinancialModel <- setRefClass("FinancialModel",
    fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", N = "numeric", M = "numeric"),
    methods = list(
        simulate_paths = function() {
            dt <- T / N
            paths <- matrix(0, nrow = N + 1, ncol = M)
            paths[1, ] <- S0
            for (i in 2:(N + 1)) {
                z <- rnorm(M)
                paths[i, ] <- paths[i - 1, ] * exp((r - 0.5 * sigma^2) * dt + sigma * sqrt(dt) * z)
            }
            return(paths)
        },
        option_price = function() {
            paths <- simulate_paths()
            payoff <- pmax(paths[N + 1, ] - K, 0)
            price <- exp(-r * T) * rowMeans(payoff)
            return(price)
        }
    )
)

main <- function() {
    S0 <- 100
    K <- 100
    T <- 1
    r <- 0.05
    sigma <- 0.2
    N <- 100
    M <- 10000
    model <- FinancialModel$new(S0 = S0, K = K, T = T, r = r, sigma = sigma, N = N, M = M)
    price <- model$option_price()
    print(price)
}

main()