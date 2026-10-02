optimize_inventory <- function(data) {
  demand <- data$demand
  supply <- data$supply
  mutations <- list()
  for (i in 1:length(demand)) {
    if (demand[i] > supply[i]) {
      mutations[[length(mutations) + 1]] <- list(type = 'adjust_supply', index = i, new_value = demand[i])
    } else {
      mutations[[length(mutations) + 1]] <- list(type = 'reduce_demand', index = i, new_value = supply[i])
    }
  }
  return(mutations)
}

apply_mutations <- function(data, mutations) {
  for (mutation in mutations) {
    if (mutation$type == 'adjust_supply') {
      data$supply[mutation$index] <- mutation$new_value
    } else if (mutation$type == 'reduce_demand') {
      data$demand[mutation$index] <- mutation$new_value
    }
  }
  return(data)
}

main <- function() {
  initial_data <- list(demand = c(100, 200, 150, 300), supply = c(120, 180, 160, 310))
  mutations <- optimize_inventory(initial_data)
  final_data <- apply_mutations(initial_data, mutations)
  print(final_data)
}

main()