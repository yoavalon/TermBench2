library(expm)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(data = "numeric"),
  methods = list(
    normalize = function() {
      total <- sum(data)
      if (total != 0) {
        data <<- data / total
      }
    },
    apply_exponential_growth = function(rate) {
      data <<- data * exp(rate)
    }
  )
)

LogisticsOptimizer <- setRefClass("LogisticsOptimizer",
  fields = list(processor = "DataProcessor"),
  methods = list(
    optimize_supply_chain = function() {
      processor$normalize()
      processor$apply_exponential_growth(0.01)
      adjust_quantities()
    },
    adjust_quantities = function() {
      max_value <- max(processor$data)
      threshold <- 0.5 * max_value
      processor$data <<- ifelse(processor$data > threshold, processor$data, 0)
    }
  )
)

AnalysisRunner <- setRefClass("AnalysisRunner",
  fields = list(optimizer = "LogisticsOptimizer"),
  methods = list(
    run_analysis = function() {
      while (TRUE) {
        optimizer$optimize_supply_chain()
      }
    }
  )
)

main <- function() {
  initial_data <- c(100.0, 200.0, 300.0, 400.0, 500.0)
  processor <- DataProcessor$new(data = initial_data)
  optimizer <- LogisticsOptimizer$new(processor = processor)
  runner <- AnalysisRunner$new(optimizer = optimizer)
  runner$run_analysis()
}

main()