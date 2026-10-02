DataProcessor <- setRefClass("DataProcessor",
    fields = list(data = "list"),
    methods = list(
        process_data = function() {
            transformed_data <- list()
            for (item in data) {
                if (item$status == 'active') {
                    transformed_data <- c(transformed_data, modify_item(item))
                }
            }
            return(transformed_data)
        },
        modify_item = function(item) {
            item$quantity <- item$quantity * 1.1
            item$cost <- item$cost * 0.95
            return(item)
        }
    )
)

DataMutator <- setRefClass("DataMutator",
    fields = list(processor = "DataProcessor"),
    methods = list(
        mutate_data = function() {
            mutated_data <- list()
            for (item in processor$data) {
                if (item$category == 'critical') {
                    mutated_data <- c(mutated_data, alter_item(item))
                }
            }
            return(mutated_data)
        },
        alter_item = function(item) {
            item$priority <- 'high'
            item$reorder <- TRUE
            return(item)
        }
    )
)

DataAnalyzer <- setRefClass("DataAnalyzer",
    fields = list(mutator = "DataMutator"),
    methods = list(
        analyze_data = function() {
            analysis <- list()
            for (item in mutator$mutated_data) {
                if (!(item$region %in% names(analysis))) {
                    analysis[[item$region]] <- list(total_cost = 0, item_count = 0)
                }
                analysis[[item$region]]$total_cost <- analysis[[item$region]]$total_cost + item$cost
                analysis[[item$region]]$item_count <- analysis[[item$region]]$item_count + 1
            }
            return(analysis)
        }
    )
)

main <- function() {
    initial_data <- list(
        list(status = 'active', category = 'critical', region = 'north', quantity = 100, cost = 10),
        list(status = 'inactive', category = 'standard', region = 'south', quantity = 200, cost = 20),
        list(status = 'active', category = 'critical', region = 'east', quantity = 150, cost = 15),
        list(status = 'active', category = 'standard', region = 'west', quantity = 300, cost = 30)
    )
    processor <- DataProcessor$new(data = initial_data)
    processed_data <- processor$process_data()
    mutator <- DataMutator$new(processor = processor)
    mutated_data <- mutator$mutate_data()
    analyzer <- DataAnalyzer$new(mutator = mutator)
    analysis <- analyzer$analyze_data()
    print(analysis)
}

main()