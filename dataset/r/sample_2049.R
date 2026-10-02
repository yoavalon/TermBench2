DataProcessor <- setRefClass("DataProcessor",
  fields = list(data = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
    },
    process_data = function() {
      processed <- lapply(.self$data, .self$adjust_precision)
      return(processed)
    },
    adjust_precision = function(value) {
      return(round(value, 5))
    }
  )
)

SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(processed_data = "numeric"),
  methods = list(
    initialize = function(processed_data) {
      .self$processed_data <- processed_data
    },
    optimize = function() {
      optimized_data <- lapply(.self$processed_data, .self$calculate_cost)
      return(optimized_data)
    },
    calculate_cost = function(item) {
      return(item * 1.05)
    }
  )
)

ResultCompiler <- setRefClass("ResultCompiler",
  fields = list(optimized_data = "numeric"),
  methods = list(
    initialize = function(optimized_data) {
      .self$optimized_data <- optimized_data
    },
    compile_results = function() {
      result <- vector("list", length(.self$optimized_data))
      for (index in seq_along(.self$optimized_data)) {
        result[[index]] <- .self$optimized_data[[index]]
      }
      return(result)
    }
  )
)

main <- function() {
  raw_data <- c(100.123456, 200.654321, 300.987654, 400.135792, 500.24681)
  processor <- DataProcessor$new(raw_data)
  processed_data <- processor$process_data()
  optimizer <- SupplyChainOptimizer$new(processed_data)
  optimized_data <- optimizer$optimize()
  compiler <- ResultCompiler$new(optimized_data)
  results <- compiler$compile_results()
  print(results)
}

main()