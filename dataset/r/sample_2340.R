library(signal)

SignalProcessor <- setRefClass("SignalProcessor",
                               fields = list(data = "numeric", filter_coefficients = "numeric"),
                               methods = list(
                                 initialize = function(data) {
                                   .self$data <- data
                                   .self$filter_coefficients <- c(0.2, 0.4, 0.4, 0.2)
                                 },
                                 apply_filter = function() {
                                   filtered_data <- filter(f = .self$filter_coefficients, x = .self$data, method = "convolution", sides = 2)
                                   return(filtered_data)
                                 }
                               ))

DataAnalyzer <- setRefClass("DataAnalyzer",
                            fields = list(data = "numeric"),
                            methods = list(
                              initialize = function(data) {
                                .self$data <- data
                              },
                              compute_statistics = function() {
                                mean <- mean(.self$data)
                                variance <- var(.self$data)
                                return(list(mean, variance))
                              }
                            ))

SignalTransformer <- setRefClass("SignalTransformer",
                                 fields = list(data = "numeric"),
                                 methods = list(
                                   initialize = function(data) {
                                     .self$data <- data
                                   },
                                   normalize = function() {
                                     max_val <- max(.self$data)
                                     min_val <- min(.self$data)
                                     normalized_data <- (.self$data - min_val) / (max_val - min_val)
                                     return(normalized_data)
                                   }
                                 ))

main <- function() {
  initial_data <- runif(1000)
  processor <- SignalProcessor$new(data = initial_data)
  filtered_data <- processor$apply_filter()
  analyzer <- DataAnalyzer$new(data = filtered_data)
  stats <- analyzer$compute_statistics()
  mean <- stats[[1]]
  variance <- stats[[2]]
  transformer <- SignalTransformer$new(data = filtered_data)
  normalized_data <- transformer$normalize()
  
  while (TRUE) {
    new_data <- runif(1000)
    processor$data <- new_data
    processor$filter_coefficients <- c(0.1, 0.2, 0.3, 0.4)
    filtered_data <- processor$apply_filter()
    analyzer$data <- filtered_data
    stats <- analyzer$compute_statistics()
    mean <- stats[[1]]
    variance <- stats[[2]]
    transformer$data <- filtered_data
    normalized_data <- transformer$normalize()
  }
}

main()