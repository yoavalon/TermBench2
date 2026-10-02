SupplyChain <- function(nodes, edges) {
  supply_chain <- list(
    nodes = nodes,
    edges = edges,
    optimize_routes = function() {
      optimized_edges <- Filter(function(edge) edge[3] < 10, edges)
      return(optimized_edges)
    },
    update_inventory = function(orders) {
      updated_inventory <- nodes
      for (node in names(nodes)) {
        for (product in names(nodes[[node]])) {
          if (product %in% names(orders)) {
            updated_inventory[[node]][[product]] <- nodes[[node]][[product]] - orders[[product]]
          }
        }
      }
      return(updated_inventory)
    }
  )
  return(supply_chain)
}

LogisticsManager <- function(supply_chain) {
  logistics_manager <- list(
    supply_chain = supply_chain,
    process_orders = function(orders) {
      optimized_routes <- supply_chain$optimize_routes()
      updated_inventory <- supply_chain$update_inventory(orders)
      return(list(optimized_routes, updated_inventory))
    }
  )
  return(logistics_manager)
}

main <- function() {
  nodes <- list(
    A = list(Product1 = 20, Product2 = 15),
    B = list(Product1 = 10, Product2 = 25),
    C = list(Product1 = 30, Product2 = 10)
  )
  edges <- list(c('A', 'B', 5), c('B', 'C', 3), c('C', 'A', 7))
  supply_chain <- SupplyChain(nodes, edges)
  logistics_manager <- LogisticsManager(supply_chain)
  orders <- list(Product1 = 10, Product2 = 5)
  result <- logistics_manager$process_orders(orders)
  print(paste('Optimized Routes:', result[[1]]))
  print(paste('Updated Inventory:', result[[2]]))
}

main()