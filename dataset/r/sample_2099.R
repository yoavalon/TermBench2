DocumentParser <- R6::R6Class("DocumentParser",
  public = list(
    text = NULL,
    initialize = function(text) {
      self$text <- text
    },
    tokenize = function() {
      tokens <- list()
      buffer <- character(0)
      for (char in strsplit(self$text, NULL)[[1]]) {
        if (grepl("[a-zA-Z0-9_]", char) | char %in% "_") {
          buffer <- c(buffer, char)
        } else {
          if (length(buffer) > 0) {
            tokens <- c(tokens, paste(buffer, collapse = ""))
            buffer <- character(0)
          }
          if (nchar(char) > 0) {
            tokens <- c(tokens, char)
          }
        }
      }
      if (length(buffer) > 0) {
        tokens <- c(tokens, paste(buffer, collapse = ""))
      }
      return(tokens)
    }
  )
)

Tokenizer <- R6::R6Class("Tokenizer",
  public = list(
    tokens = NULL,
    initialize = function(tokens) {
      self$tokens <- tokens
    },
    categorize = function() {
      categorized <- list()
      for (token in self$tokens) {
        if (grepl("^[0-9]+$", token)) {
          categorized <- c(categorized, "Number")
        } else if (grepl("^[0-9]+\\.[0-9]+$", token)) {
          categorized <- c(categorized, "Float")
        } else if (grepl("^[a-zA-Z0-9_]+$", token)) {
          categorized <- c(categorized, "Identifier")
        } else {
          categorized <- c(categorized, "Operator")
        }
      }
      return(categorized)
    }
  )
)

main <- function() {
  text <- 'x = 3.14 * 2 + 5.0'
  parser <- DocumentParser$new(text)
  tokens <- parser$tokenize()
  tokenizer <- Tokenizer$new(tokens)
  categorized <- tokenizer$categorize()
  print(categorized)
}

main()