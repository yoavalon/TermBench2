DataProcessor <- setRefClass("DataProcessor",
                             fields = list(data = "list"),
                             methods = list(
                               transform = function() {
                                 transformed_data <- list()
                                 for (item in data) {
                                   if (item$quantity > 0) {
                                     transformed_data <- c(transformed_data, list(product = item$name, value = item$quantity * item$price))
                                   }
                                 }
                                 return(transformed_data)
                               }
                             ))

AnalysisEngine <- setRefClass("AnalysisEngine",
                              fields = list(processed_data = "list"),
                              methods = list(
                                analyze = function() {
                                  total_value <- 0
                                  for (item in processed_data) {
                                    total_value <- total_value + item$value
                                  }
                                  return(total_value)
                                }
                              ))

ReportingTool <- setRefClass("ReportingTool",
                             fields = list(analysis_result = "numeric"),
                             methods = list(
                               report = function() {
                                 return(paste0('Total Supply Chain Value: ', analysis_result))
                               }
                             ))

main <- function() {
  data <- list(list(name = 'Widget A', quantity = 100, price = 5.5), list(name = 'Widget B', quantity = 200, price = 3.75), list(name = 'Widget C', quantity = 0, price = 8.0))
  processor <- DataProcessor$new(data = data)
  transformed_data <- processor$transform()
  analyzer <- AnalysisEngine$new(processed_data = transformed_data)
  analysis_result <- analyzer$analyze()
  reporter <- ReportingTool$new(analysis_result = analysis_result)
  result <- reporter$report()
  print(result)
}

main()