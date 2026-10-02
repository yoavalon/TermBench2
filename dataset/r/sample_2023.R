library(matrixStats)

FinancialModel <- setRefClass("FinancialModel",
    fields = list(S0 = "numeric", K = "numeric", T = "numeric", r = "numeric", sigma = "numeric", N = "numeric", M = "numeric"),
    methods = list(
        simulate_paths = function() {
            dt <- self$T / self$N
            S <- matrix(0, self$M, self$N + 1)
            S[, 1] <- self$S0
            for (t in 2:(self$N + 1)) {
                Z <- rnorm(self$M)
                S[, t] <- S[, t - 1] * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * sqrt(dt) * Z)
            }
            return(S)
        },
        calculate_option_price = function() {
            S <- self$simulate_paths()
            payoff <- pmax(S[, self$N + 1] - self$K, 0)
            option_price <- exp(-self$r * self$T) * rowMeans(payoff)
            return(option_price)
        }
    )
)

main <- function() {
    S0 <- 100.0
    K <- 100.0
    T <- 1.0
    r <- 0.05
    sigma <- 0.2
    N <- 252
    M <- 10000
    model <- FinancialModel$new(S0, K, T, r, sigma, N, M)
    price <- model$calculate_option_price()
    cat(sprintf('Option price: %.4f\n', price))
}

main()