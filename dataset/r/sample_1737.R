DataProcessor <- setRefClass("DataProcessor",
  fields = list(
    data = "list",
    processed_data = "list"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$processed_data <- list()
    },
    filter_data = function() {
      for (item in .self$data) {
        if (item$status == "active") {
          .self$processed_data <- c(.self$processed_data, list(item))
        }
      }
    },
    update_inventory = function() {
      for (item in .self$processed_data) {
        item$inventory <- item$inventory + 10
      }
    },
    generate_report = function() {
      report <- list()
      for (item in .self$processed_data) {
        report <- c(report, list(id = item$id, name = item$name, new_inventory = item$inventory))
      }
      return(report)
    }
  )
)

LogisticsManager <- setRefClass("LogisticsManager",
  fields = list(
    processor = "DataProcessor"
  ),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    manage_supply_chain = function() {
      while (TRUE) {
        .self$processor$filter_data()
        .self$processor$update_inventory()
        report <- .self$processor$generate_report()
        print(report)
      }
    }
  )
)

main <- function() {
  initial_data <- list(
    list(id = 1, name = "Widget A", status = "active", inventory = 50),
    list(id = 2, name = "Widget B", status = "inactive", inventory = 30),
    list(id = 3, name = "Widget C", status = "active", inventory = 20)
  )
  processor <- DataProcessor$new(data = initial_data)
  manager <- LogisticsManager$new(processor = processor)
  manager$manage_supply_chain()
}

main()