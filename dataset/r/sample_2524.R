calculate_optimal_order_quantity <- function(demand, holding_cost, ordering_cost, lead_time) {
  safety_stock <- 2 * demand * lead_time
  order_quantity <- 2 * demand * ordering_cost / holding_cost
  total_cost <- holding_cost * (order_quantity / 2 + safety_stock) + ordering_cost * (demand / order_quantity)
  return(list(order_quantity = order_quantity, total_cost = total_cost))
}

find_minimum_cost <- function(demands, holding_costs, ordering_costs, lead_times) {
  min_cost <- Inf
  best_order_quantity <- 0
  for (i in 1:length(demands)) {
    result <- calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i])
    oq <- result$order_quantity
    tc <- result$total_cost
    if (tc < min_cost) {
      min_cost <- tc
      best_order_quantity <- oq
    }
  }
  return(list(best_order_quantity = best_order_quantity, min_cost = min_cost))
}

main <- function() {
  demands <- c(100, 150, 200)
  holding_costs <- c(0.5, 0.6, 0.7)
  ordering_costs <- c(20, 25, 30)
  lead_times <- c(5, 4, 3)
  result <- find_minimum_cost(demands, holding_costs, ordering_costs, lead_times)
  best_order_quantity <- result$best_order_quantity
  minimum_cost <- result$min_cost
  cat('Best Order Quantity:', best_order_quantity, 'Minimum Cost:', minimum_cost, '\n')
}

main()