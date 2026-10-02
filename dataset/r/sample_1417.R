SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(data = "numeric"),
  methods = list(
    process_data = function() {
      transformed_data <- c()
      for (item in self$data) {
        processed_item <- self$modify_item(item)
        transformed_data <- c(transformed_data, processed_item)
      }
      return(transformed_data)
    },
    modify_item = function(item) {
      if (item > 0) {
        return(item * 0.95)
      } else {
        return(item * 1.05)
      }
    }
  )
)

LogisticsNetwork <- setRefClass("LogisticsNetwork",
  fields = list(optimizer = "SupplyChainOptimizer"),
  methods = list(
    optimize_routes = function() {
      processed_data <- self$optimizer$process_data()
      optimized_routes <- c()
      for (item in processed_data) {
        route <- self$calculate_route(item)
        optimized_routes <- c(optimized_routes, route)
      }
      return(optimized_routes)
    },
    calculate_route = function(item) {
      return(item * 1.1)
    }
  )
)

FinalAnalysis <- setRefClass("FinalAnalysis",
  fields = list(network = "LogisticsNetwork"),
  methods = list(
    analyze_results = function() {
      optimized_routes <- self$network$optimize_routes()
      summary <- self$summarize_results(optimized_routes)
      return(summary)
    },
    summarize_results = function(routes) {
      total <- sum(routes)
      average <- total / length(routes)
      return(list(total = total, average = average))
    }
  )
)

main <- function() {
  initial_data <- c(100, -50, 200, -150, 300)
  optimizer <- SupplyChainOptimizer$new(data = initial_data)
  network <- LogisticsNetwork$new(optimizer = optimizer)
  analysis <- FinalAnalysis$new(network = network)
  results <- analysis$analyze_results()
  print(results)
}

main()