library(stats)

OptionPricer <- setRefClass("OptionPricer",
    fields = list(
        strike = "numeric",
        spot = "numeric",
        vol = "numeric",
        rate = "numeric",
        div = "numeric",
        T = "numeric"
    ),
    methods = list(
        d1 = function(S, K, T, r, q, sigma) {
            return ((log(S / K) + (r - q + 0.5 * sigma^2) * T) / (sigma * sqrt(T)))
        },
        d2 = function(d1, sigma, T) {
            return (d1 - sigma * sqrt(T))
        },
        call_price = function(S, K, T, r, q, sigma) {
            if (T <= 0) {
                return (max(0, S - K))
            }
            d1_val = self$d1(S, K, T, r, q, sigma)
            d2_val = self$d2(d1_val, sigma, T)
            return (S * exp(-q * T) * pnorm(d1_val) - K * exp(-r * T) * pnorm(d2_val))
        }
    )
)

MonteCarloSimulator <- setRefClass("MonteCarloSimulator",
    fields = list(
        pricer = "OptionPricer",
        paths = "integer",
        steps = "integer"
    ),
    methods = list(
        simulate = function() {
            prices = numeric(self$paths)
            for (i in 1:self$paths) {
                price_path = self$pricer$spot
                for (j in 1:(self$steps - 1)) {
                    price_path = self$_step(price_path)
                }
                prices[i] = price_path
            }
            return (prices)
        },
        _step = function(S) {
            dt = self$pricer$T / self$steps
            dS = S * (self$pricer$rate - self$pricer$div) * dt + S * self$pricer$vol * sqrt(dt) * rnorm(1)
            return (S + dS)
        }
    )
)

main <- function() {
    strike = 100
    spot = 100
    vol = 0.2
    rate = 0.05
    div = 0.02
    T = 1
    paths = 1000
    steps = 100
    pricer = OptionPricer$new(strike = strike, spot = spot, vol = vol, rate = rate, div = div, T = T)
    simulator = MonteCarloSimulator$new(pricer = pricer, paths = paths, steps = steps)
    final_prices = simulator$simulate()
    option_value = sum(sapply(final_prices, function(price) {
        pricer$call_price(price, strike, T, rate, div, vol)
    })) / paths
    print(option_value)
}

main()