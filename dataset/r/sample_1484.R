library(stats)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(data = "numeric"),
  methods = list(
    mutate_data = function() {
      mutated <- numeric(length(self$data))
      for (i in 1:length(self$data)) {
        mutated[i] <- self$data[i] + runif(1, -0.1, 0.1)
      }
      return(mutated)
    }
  )
)

OptionPricer <- setRefClass("OptionPricer",
  fields = list(data = "numeric"),
  methods = list(
    calculate_price = function() {
      prices <- numeric(length(self$data))
      for (i in 1:length(self$data)) {
        prices[i] <- self$black_scholes(self$data[i])
      }
      return(prices)
    },
    black_scholes = function(S) {
      K <- 100
      T <- 1
      r <- 0.05
      sigma <- 0.2
      d1 <- (log(S / K) + (r + 0.5 * sigma ^ 2) * T) / (sigma * sqrt(T))
      d2 <- d1 - sigma * sqrt(T)
      call_price <- S * exp(-r * T) * self$norm_cdf(d1) - K * exp(-r * T) * self$norm_cdf(d2)
      return(call_price)
    },
    norm_cdf = function(x) {
      return((1.0 + pnorm(x / sqrt(2.0))) / 2.0)
    }
  )
)

TerminationAnalyzer <- setRefClass("TerminationAnalyzer",
  fields = list(data = "numeric"),
  methods = list(
    analyze = function() {
      analysis <- logical(length(self$data))
      for (i in 1:length(self$data)) {
        analysis[i] <- self$determine_termination(self$data[i])
      }
      return(analysis)
    },
    determine_termination = function(item) {
      return(item > 100)
    }
  )
)

main <- function() {
  initial_data <- c(90, 100, 110, 120, 130)
  processor <- DataProcessor$new(data = initial_data)
  mutated_data <- processor$mutate_data()
  pricer <- OptionPricer$new(data = mutated_data)
  prices <- pricer$calculate_price()
  analyzer <- TerminationAnalyzer$new(data = prices)
  analysis <- analyzer$analyze()
  print(analysis)
}

main()