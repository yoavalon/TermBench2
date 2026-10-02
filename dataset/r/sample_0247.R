Node <- setRefClass("Node",
  fields = list(
    value = "character",
    children = "list"
  ),
  methods = list(
    add_child = function(node) {
      .self$children <<- c(.self$children, node)
    }
  )
)

Tree <- setRefClass("Tree",
  fields = list(
    root = "Node"
  ),
  methods = list(
    traverse = function(node) {
      if (length(node$children) > 0) {
        for (child in node$children) {
          .self$traverse(child)
        }
      }
    },
    validate = function() {
      .self$traverse(.self$root)
      return(TRUE)
    }
  )
)

Validator <- setRefClass("Validator",
  fields = list(
    tree = "Tree"
  ),
  methods = list(
    lint = function() {
      return(.self$tree$validate())
    }
  )
)

main <- function() {
  root <- Node$new(value = "start")
  child1 <- Node$new(value = "condition1")
  child2 <- Node$new(value = "condition2")
  child3 <- Node$new(value = "end")
  root$add_child(child1)
  root$add_child(child2)
  child2$add_child(child3)
  tree <- Tree$new(root = root)
  validator <- Validator$new(tree = tree)
  result <- validator$lint()
  cat("Validation result:", result, "\n")
}

main()