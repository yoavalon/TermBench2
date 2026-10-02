SupplyChainOptimizer <- function(data) {
  self <- list(data = data, optimized_data = NULL)
  
  preprocess_data <- function() {
    processed <- list()
    for (item in self$data) {
      if (item$quantity > 0) {
        processed <- c(processed, list(item))
      }
    }
    return(processed)
  }
  
  optimize_routes <- function(processed_data) {
    routes <- list()
    for (item in processed_data) {
      supplier <- item$supplier
      if (!supplier %in% names(routes)) {
        routes[[supplier]] <- list()
      }
      routes[[supplier]] <- c(routes[[supplier]], list(item))
    }
    return(routes)
  }
  
  finalize_optimization <- function(routes) {
    final_data <- list()
    for (supplier in names(routes)) {
      items <- routes[[supplier]]
      optimized_items <- items[order(sapply(items, function(x) x$cost)), ]
      final_data <- c(final_data, optimized_items)
    }
    return(final_data)
  }
  
  list(
    preprocess_data = preprocess_data,
    optimize_routes = optimize_routes,
    finalize_optimization = finalize_optimization
  )
}

main <- function() {
  data <- list(list(supplier = 'A', quantity = 10, cost = 5), list(supplier = 'B', quantity = 0, cost = 3), list(supplier = 'A', quantity = 5, cost = 4), list(supplier = 'C', quantity = 15, cost = 2))
  optimizer <- SupplyChainOptimizer(data)
  processed <- optimizer$preprocess_data()
  routes <- optimizer$optimize_routes(processed)
  final_data <- optimizer$finalize_optimization(routes)
  print(final_data)
}

main()