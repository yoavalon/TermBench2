SupplyChain <- setRefClass("SupplyChain",
  fields = list(
    demand = "numeric",
    supply = "numeric",
    inventory = "numeric",
    shortage = "numeric"
  ),
  methods = list(
    initialize = function(demand, supply) {
      .self$demand <- demand
      .self$supply <- supply
      .self$inventory <- supply
      .self$shortage <- 0
    },
    update_inventory = function() {
      if (.self$demand > .self$supply) {
        .self$shortage <<- .self$demand - .self$supply
        .self$inventory <<- 0
      } else {
        .self$inventory <<- .self$inventory - .self$demand
        .self$shortage <<- 0
      }
    },
    adjust_supply = function(adjustment) {
      .self$supply <<- .self$supply + adjustment
    }
  )
)

Optimizer <- setRefClass("Optimizer",
  fields = list(
    supply_chain = "SupplyChain"
  ),
  methods = list(
    initialize = function(supply_chain) {
      .self$supply_chain <<- supply_chain
    },
    optimize = function() {
      shortage <- .self$supply_chain$shortage
      if (shortage > 0) {
        adjustment <- shortage * 1.1
        .self$supply_chain$adjust_supply(adjustment)
      }
    }
  )
)

main <- function() {
  demand <- 150
  supply <- 100
  supply_chain <- SupplyChain$new(demand, supply)
  optimizer <- Optimizer$new(supply_chain)
  while (TRUE) {
    supply_chain$update_inventory()
    optimizer$optimize()
  }
}

main()