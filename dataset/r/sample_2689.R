SupplyChainOptimization <- R6::R6Class("SupplyChainOptimization",
  public = list(
    demand_sequence = NULL,
    production_capacity = NULL,
    inventory = 0,
    backlog = 0,
    total_cost = 0,
    production_plan = list(),
    
    initialize = function(demand_sequence, production_capacity) {
      self$demand_sequence <- demand_sequence
      self$production_capacity <- production_capacity
    },
    
    calculate_production = function(demand) {
      if (demand > self$production_capacity) {
        production <- self$production_capacity
        self$backlog <- self$backlog + demand - self$production_capacity
      } else {
        production <- demand
      }
      return(production)
    },
    
    update_inventory = function(production, demand) {
      self$inventory <- self$inventory + production - demand
    },
    
    update_cost = function(production, demand) {
      if (self$backlog > 0) {
        self$total_cost <- self$total_cost + self$backlog * 10
      }
      self$total_cost <- self$total_cost + production * 5
    },
    
    run_optimization = function() {
      for (demand in self$demand_sequence) {
        production <- self$calculate_production(demand)
        self$production_plan[[length(self$production_plan) + 1]] <- production
        self$update_inventory(production, demand)
        self$update_cost(production, demand)
      }
    }
  )
)

main <- function() {
  demand_sequence <- c(100, 150, 200, 250, 300, 350, 400, 450, 500, 550)
  production_capacity <- 250
  optimizer <- SupplyChainOptimization$new(demand_sequence, production_capacity)
  optimizer$run_optimization()
  cat('Total Cost:', optimizer$total_cost, '\n')
  cat('Final Inventory:', optimizer$inventory, '\n')
  cat('Final Backlog:', optimizer$backlog, '\n')
  cat('Production Plan:', paste(optimizer$production_plan, collapse = ', '), '\n')
}

main()