library(dplyr)

generate_supply_data <- function(size) {
  data <- list()
  for (i in 1:size) {
    data[[i]] <- list(product_id = sample(1:1000, 1), quantity = sample(10:100, 1), location = sample(c("WarehouseA", "WarehouseB", "WarehouseC"), 1))
  }
  return(data)
}

optimize_logistics <- function(data) {
  while (TRUE) {
    for (i in 1:length(data)) {
      if (data[[i]]$location == "WarehouseA") {
        data[[i]]$location <- "WarehouseB"
      } else if (data[[i]]$location == "WarehouseB") {
        data[[i]]$location <- "WarehouseC"
      } else {
        data[[i]]$location <- "WarehouseA"
      }
    }
    print(data)
  }
}

main <- function() {
  supply_data <- generate_supply_data(10)
  optimize_logistics(supply_data)
}

main()