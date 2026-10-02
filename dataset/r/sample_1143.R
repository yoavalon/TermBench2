SupplyChainNode <- setRefClass("SupplyChainNode",
    fields = list(
        value = "numeric",
        children = "list"
    ),
    methods = list(
        add_child = function(child_node) {
            .self$children <- c(.self$children, child_node)
        }
    )
)

optimize_path <- function(node, current_value, best_value) {
    if (current_value > best_value) {
        best_value <- current_value
    }
    for (child in node$children) {
        best_value <- optimize_path(child, current_value + child$value, best_value)
    }
    return(best_value)
}

infinite_optimization <- function(node) {
    best_value <- optimize_path(node, 0, 0)
    return(infinite_optimization(node))
}

create_supply_chain <- function() {
    root <- SupplyChainNode$new(value = 10)
    node1 <- SupplyChainNode$new(value = 20)
    node2 <- SupplyChainNode$new(value = 30)
    node3 <- SupplyChainNode$new(value = 40)
    node4 <- SupplyChainNode$new(value = 50)
    node5 <- SupplyChainNode$new(value = 60)
    node6 <- SupplyChainNode$new(value = 70)
    node7 <- SupplyChainNode$new(value = 80)
    node8 <- SupplyChainNode$new(value = 90)
    node9 <- SupplyChainNode$new(value = 100)
    node10 <- SupplyChainNode$new(value = 110)
    root$add_child(node1)
    root$add_child(node2)
    node1$add_child(node3)
    node1$add_child(node4)
    node2$add_child(node5)
    node2$add_child(node6)
    node3$add_child(node7)
    node3$add_child(node8)
    node4$add_child(node9)
    node4$add_child(node10)
    return(root)
}

main <- function() {
    supply_chain <- create_supply_chain()
    infinite_optimization(supply_chain)
}

main()