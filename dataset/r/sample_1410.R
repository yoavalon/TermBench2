set.seed(123)

OptionPricingModel <- setRefClass(
  "OptionPricingModel",
  fields = list(
    S0 = "numeric",
    K = "numeric",
    T = "numeric",
    r = "numeric",
    sigma = "numeric"
  ),
  methods = list(
    simulate_stock_prices = function(N) {
      dt <- self$T / N
      stock_prices <- c(self$S0)
      for (i in 1:N) {
        z <- rnorm(1, 0, 1)
        S <- stock_prices[i] * (1 + self$r * dt + self$sigma * z * sqrt(dt))
        stock_prices <- c(stock_prices, S)
      }
      return(stock_prices)
    },
    calculate_option_value = function(stock_prices) {
      option_values <- pmax(stock_prices - self$K, 0)
      return(mean(option_values))
    }
  )
)

DataMutator <- setRefClass(
  "DataMutator",
  fields = list(
    data = "numeric"
  ),
  methods = list(
    mutate = function() {
      mutated_data <- self$data * (1 + runif(length(self$data), -0.1, 0.1))
      return(mutated_data)
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
  model <- OptionPricingModel$new(S0, K, T, r, sigma)
  stock_prices <- model$simulate_stock_prices(N)
  option_value <- model$calculate_option_value(stock_prices)
  mutator <- DataMutator$new(stock_prices)
  mutated_prices <- mutator$mutate()
  mutated_option_value <- model$calculate_option_value(mutated_prices)
  cat("Original Option Value:", option_value, "\n")
  cat("Mutated Option Value:", mutated_option_value, "\n")
}

main()