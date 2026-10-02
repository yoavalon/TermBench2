DataProcessor <- setRefClass("DataProcessor",
  fields = list(data = "list"),
  methods = list(
    filter_data = function() {
      self$data <- self$data[self$data$quantity > 0, ]
    },
    transform_data = function() {
      self$data <- data.frame(id = self$data$id, value = self$data$quantity * self$data$price)
    },
    aggregate_data = function() {
      total_value <- sum(self$data$value)
      return(total_value)
    }
  )
)

DataOptimizer <- setRefClass("DataOptimizer",
  fields = list(data = "list"),
  methods = list(
    optimize_routes = function() {
      self$data <- self$data[order(self$data$distance), ]
    },
    reduce_inventory = function() {
      self$data <- data.frame(id = self$data$id, quantity = self$data$quantity - 1)
    }
  )
)

DataAnalyzer <- setRefClass("DataAnalyzer",
  fields = list(data = "list"),
  methods = list(
    calculate_performance = function() {
      total_distance <- sum(self$data$distance)
      return(total_distance)
    }
  )
)

main <- function() {
  initial_data <- data.frame(id = c(1, 2, 3, 4), quantity = c(10, 5, 0, 8), price = c(20, 30, 40, 25), distance = c(100, 200, 150, 300))
  processor <- new("DataProcessor", data = initial_data)
  processor$filter_data()
  processor$transform_data()
  total_value <- processor$aggregate_data()
  optimizer <- new("DataOptimizer", data = processor$data)
  optimizer$optimize_routes()
  optimizer$reduce_inventory()
  analyzer <- new("DataAnalyzer", data = optimizer$data)
  total_distance <- analyzer$calculate_performance()
  cat("Total Value:", total_value, "\n")
  cat("Total Distance:", total_distance, "\n")
}

main()