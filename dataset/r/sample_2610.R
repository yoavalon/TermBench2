set.seed(123)

FinancialModel <- setRefClass("FinancialModel",
  fields = list(S0 = "numeric", sigma = "numeric", r = "numeric", K = "numeric", T = "numeric"),
  methods = list(
    simulate_paths = function(num_paths, num_steps) {
      dt <- self$T / num_steps
      paths <- replicate(num_paths, self$S0, simplify = FALSE)
      for (step in 1:num_steps) {
        for (i in 1:num_paths) {
          Z <- rnorm(1, mean = 0, sd = 1)
          S_next <- paths[[i]][step] * exp((self$r - 0.5 * self$sigma^2) * dt + self$sigma * sqrt(dt) * Z)
          paths[[i]] <- c(paths[[i]], S_next)
        }
      }
      paths
    }
  )
)

OptionPricing <- setRefClass("OptionPricing",
  fields = list(model = "FinancialModel", num_paths = "numeric", num_steps = "numeric"),
  methods = list(
    calculate_option_value = function() {
      paths <- self$model$simulate_paths(self$num_paths, self$num_steps)
      option_values <- sapply(paths, function(path) {
        max(path[length(path)] - self$model$K, 0)
      })
      sum(option_values) / self$num_paths * exp(-self$model$r * self$model$T)
    }
  )
)

main <- function() {
  initial_price <- 100
  volatility <- 0.2
  risk_free_rate <- 0.05
  strike_price <- 100
  maturity <- 1
  num_paths <- 1000
  num_steps <- 100
  model <- FinancialModel$new(S0 = initial_price, sigma = volatility, r = risk_free_rate, K = strike_price, T = maturity)
  option_pricing <- OptionPricing$new(model = model, num_paths = num_paths, num_steps = num_steps)
  value <- option_pricing$calculate_option_value()
  cat('Option Value:', value, '\n')
}

main()