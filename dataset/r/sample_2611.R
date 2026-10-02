SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(current = "numeric", increment = "numeric"),
  methods = list(
    initialize = function(start, increment) {
      .self$current <- start
      .self$increment <- increment
    },
    generate = function(count) {
      sequence <- numeric(count)
      for (i in 1:count) {
        sequence[i] <- .self$current
        .self$current <- .self$current + .self$increment
      }
      return(sequence)
    }
  )
)

SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
  fields = list(demand = "numeric", supply = "numeric"),
  methods = list(
    initialize = function(demand, supply) {
      .self$demand <- demand
      .self$supply <- supply
    },
    calculate_deficit = function() {
      deficit <- .self$demand - .self$supply
      return(max(deficit, 0))
    },
    optimize_supply = function(additional_supply) {
      .self$supply <- .self$supply + additional_supply
    }
  )
)

SupplyChain <- setRefClass("SupplyChain",
  fields = list(demand_sequence = "numeric", supply_sequence = "numeric", optimizer = "SupplyChainOptimizer"),
  methods = list(
    initialize = function(demand_sequence, supply_sequence) {
      .self$demand_sequence <- demand_sequence
      .self$supply_sequence <- supply_sequence
      .self$optimizer <- SupplyChainOptimizer$new(0, 0)
    },
    run_optimization = function() {
      for (i in seq_along(.self$demand_sequence)) {
        demand <- .self$demand_sequence[i]
        supply <- .self$supply_sequence[i]
        .self$optimizer$supply <- supply
        deficit <- .self$optimizer$calculate_deficit()
        if (deficit > 0) {
          additional_supply <- SequenceGenerator$new(deficit, 1)$generate(1)[1]
          .self$optimizer$optimize_supply(additional_supply)
        }
        cat(sprintf("Demand: %d, Supply: %d, Deficit: %d, Adjusted Supply: %d\n", demand, supply, deficit, .self$optimizer$supply))
      }
    }
  )
)

main <- function() {
  demand_gen <- SequenceGenerator$new(100, 10)
  demand_sequence <- demand_gen$generate(10)
  supply_gen <- SequenceGenerator$new(80, 5)
  supply_sequence <- supply_gen$generate(10)
  supply_chain <- SupplyChain$new(demand_sequence, supply_sequence)
  supply_chain$run_optimization()
}

main()