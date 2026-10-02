library(dplyr)
library(tidyr)

load_data <- function() {
  data.frame(id = 1:100, quantity = sample(1:99, 100, replace = TRUE), cost = runif(100) * 1000)
}

optimize_supply_chain <- function(data) {
  data$optimized_quantity <- data$quantity * 1.1
  data$total_cost <- data$optimized_quantity * data$cost
  return(data)
}

process_data <- function() {
  df <- load_data()
  optimized_df <- optimize_supply_chain(df)
  return(optimized_df)
}

main <- function() {
  result <- process_data()
  print(head(result))
}

main()