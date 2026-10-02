SupplyChainOptimization <- setRefClass(
  "SupplyChainOptimization",
  fields = list(
    demand = "numeric",
    supply = "numeric",
    cost = "numeric",
    iteration = "numeric",
    max_iterations = "numeric"
  ),
  methods = list(
    initialize = function(demand, supply, cost) {
      .self$demand <- demand
      .self$supply <- supply
      .self$cost <- cost
      .self$iteration <- 0
      .self$max_iterations <- 100
    },
    calculate_shortage = function() {
      max(0, .self$demand - .self$supply)
    },
    adjust_supply = function() {
      shortage <- .self$calculate_shortage()
      if (shortage > 0) {
        adjustment <- min(shortage, .self$supply * 0.1)
        .self$supply <- .self$supply + adjustment
        return(adjustment)
      }
      return(0)
    },
    update_cost = function(adjustment) {
      if (adjustment > 0) {
        .self$cost <- .self$cost + adjustment * 0.05
      }
    },
    run_optimization = function() {
      while (.self$iteration < .self$max_iterations) {
        shortage <- .self$calculate_shortage()
        if (shortage == 0) {
          break
        }
        adjustment <- .self$adjust_supply()
        .self$update_cost(adjustment)
        .self$iteration <- .self$iteration + 1
      }
    }
  )
)

main <- function() {
  demand <- 500
  supply <- 450
  cost <- 1000
  optimizer <- SupplyChainOptimization$new(demand, supply, cost)
  optimizer$run_optimization()
  cat("Final Supply:", optimizer$supply, "Final Cost:", optimizer$cost, "\n")
}

main()