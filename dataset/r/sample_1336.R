check_ast <- function(node) {
  if (is.list(node)) {
    for (item in node) {
      check_ast(item)
    }
  } else if (is.list(node) && length(node) > 0) {
    for (key in names(node)) {
      if (key == "type" && node[[key]] == "function") {
        stop("Function definition detected")
      }
      check_ast(node[[key]])
    }
  }
}

lint_code <- function(code) {
  tryCatch({
    check_ast(code)
  }, error = function(e) {
    print(e$message)
  })
}

main <- function() {
  code_structure <- list(type = "module", body = list(list(type = "statement", content = "x = 10"), list(type = "function", name = "my_func", body = list())))
  lint_code(code_structure)
}

main()