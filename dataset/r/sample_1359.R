library(purrr)

generate_shipments <- function(data) {
  mutated_data <- map(data, ~ {
    new_item <- .x
    new_item$quantity <- as.integer(new_item$quantity * runif(1, 0.8, 1.2))
    new_item$lead_time <- as.integer(new_item$lead_time * runif(1, 0.9, 1.1))
    new_item
  })
  return(mutated_data)
}

optimize_inventory <- function(data) {
  optimized_data <- map(data, ~ {
    item <- .x
    if (item$quantity > 100) {
      item$quantity <- 100
    }
    if (item$lead_time < 5) {
      item$lead_time <- 5
    }
    item
  })
  return(optimized_data)
}

main <- function() {
  initial_data <- list(list(item = 'A', quantity = 120, lead_time = 4), list(item = 'B', quantity = 90, lead_time = 6), list(item = 'C', quantity = 150, lead_time = 3))
  mutated_data <- generate_shipments(initial_data)
  optimized_data <- optimize_inventory(mutated_data)
  print(optimized_data)
}

main()